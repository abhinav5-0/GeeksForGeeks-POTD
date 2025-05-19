class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* predecessor = nullptr;
        Node* successor = nullptr;

        while (root != nullptr) {
            if (root->data == key) {
                // Predecessor is max value in left subtree
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right)
                        temp = temp->right;
                    predecessor = temp;
                }

                // Successor is min value in right subtree
                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left)
                        temp = temp->left;
                    successor = temp;
                }
                break;
            }
            else if (key < root->data) {
                successor = root;
                root = root->left;
            }
            else {
                predecessor = root;
                root = root->right;
            }
        }

        return {predecessor, successor};
    }
};
