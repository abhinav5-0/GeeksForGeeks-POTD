class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
        node->word = word;
    }

    void dfs(TrieNode* node, string& best) {
        if (!node->isEnd && node != root) return;

        if (node->word.size() > best.size() || 
           (node->word.size() == best.size() && node->word < best)) {
            best = node->word;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i])
                dfs(node->children[i], best);
        }
    }

    string longestString(vector<string> &words) {
        for (string& word : words) {
            insert(word);
        }

        string best = "";
        dfs(root, best);
        return best;
    }
};
