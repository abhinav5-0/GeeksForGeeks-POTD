class Solution {
public:
    vector<int> findPreSuc(Node* root, int key) {
        Node* temp = root;
        int pre = -1, suc = -1;

        // Find predecessor
        while (temp) {
            if (key > temp->data) {
                pre = temp->data;
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        temp = root;

        // Find successor
        while (temp) {
            if (key < temp->data) {
                suc = temp->data;
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        return {pre, suc};
    }
};
