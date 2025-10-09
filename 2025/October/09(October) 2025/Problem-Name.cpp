/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        postOrderTraversal(root, ans);
        return ans;
    }
    
  private:
    void postOrderTraversal(Node* node, vector<int>& ans) {
        if (node == NULL) return;
        
        // 1️⃣ Traverse left subtree
        postOrderTraversal(node->left, ans);
        
        // 2️⃣ Traverse right subtree
        postOrderTraversal(node->right, ans);
        
        // 3️⃣ Visit current node
        ans.push_back(node->data);
    }
};
