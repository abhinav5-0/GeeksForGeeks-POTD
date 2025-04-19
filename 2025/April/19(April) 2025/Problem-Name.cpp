class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->child[toggledBit]) {
                maxXor |= (1 << i);
                node = node->child[toggledBit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int maxXor(vector<int>& arr) {
        Trie trie;
        int result = 0;
        trie.insert(arr[0]);

        for (int i = 1; i < arr.size(); ++i) {
            result = max(result, trie.getMaxXor(arr[i]));
            trie.insert(arr[i]);
        }

        return result;
    }
};
