class Solution {
  public:
    Node *first, *middle, *last, *prev;
    
    void inorderTraversal(Node* root) {
        if (!root) return;
        
        inorderTraversal(root->left);
        
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        
        inorderTraversal(root->right);
    }
    
    void correctBST(Node* root) {
        first = middle = last = prev = nullptr;
        
        inorderTraversal(root);
        
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
};
