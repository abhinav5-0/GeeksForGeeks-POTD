class Solution {
public:

    bool isIdentical(Node* a, Node* b) {

        // Both trees are empty
        if(a == NULL && b == NULL)
            return true;

        // One tree is empty
        if(a == NULL || b == NULL)
            return false;

        // Check current node and subtrees
        return (a->data == b->data) &&
               isIdentical(a->left, b->left) &&
               isIdentical(a->right, b->right);
    }

    bool isSubTree(Node* root1, Node* root2) {

        // Empty subtree is always subtree
        if(root2 == NULL)
            return true;

        // Main tree empty
        if(root1 == NULL)
            return false;

        // Check if identical from current node
        if(isIdentical(root1, root2))
            return true;

        // Recur for left and right subtree
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};
