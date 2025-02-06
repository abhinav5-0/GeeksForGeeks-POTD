class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

    // Function to construct the tree recursively
    Node* constructTree(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        // Pick the current node from preorder traversal
        int curr = preorder[preIndex++];
        Node* node = new Node(curr);

        // If the node has no children, return it
        if (inStart == inEnd)
            return node;

        // Find the index of this node in inorder traversal
        int inIndex = inorderMap[curr];

        // Construct left and right subtrees
        node->left = constructTree(preorder, inorder, inStart, inIndex - 1);
        node->right = constructTree(preorder, inorder, inIndex + 1, inEnd);

        return node;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        inorderMap.clear();
        preIndex = 0;

        // Store the inorder values in a hashmap for quick lookup
        for (int i = 0; i < n; i++)
            inorderMap[inorder[i]] = i;

        return constructTree(preorder, inorder, 0, n - 1);
    }
};
