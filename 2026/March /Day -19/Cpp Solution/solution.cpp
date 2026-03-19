class NodeInfo {
public:
    int minVal, maxVal, size;
    bool isBST;

    NodeInfo(int minVal, int maxVal, int size, bool isBST) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->size = size;
        this->isBST = isBST;
    }
};

class Solution {
public:
    int maxSize = 0;

    NodeInfo solve(Node* root) {
        if (!root) 
            return NodeInfo(INT_MAX, INT_MIN, 0, true);

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.isBST && right.isBST &&
            root->data > left.maxVal && root->data < right.minVal) {

            int size = left.size + right.size + 1;
            maxSize = max(maxSize, size);

            return NodeInfo(
                min(root->data, left.minVal),
                max(root->data, right.maxVal),
                size,
                true
            );
        }

        return NodeInfo(INT_MIN, INT_MAX, max(left.size, right.size), false);
    }

    int largestBst(Node *root) {
        solve(root);
        return maxSize;
    }
};
