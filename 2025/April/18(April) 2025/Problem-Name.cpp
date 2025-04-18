class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert word into the Trie
    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // Search for the exact word in the Trie
    bool search(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false; // Word does not exist
            }
            node = node->children[c];
        }
        return node->isEndOfWord; // Return true if it's a complete word
    }

    // Check if there's any word that starts with the given prefix
    bool isPrefix(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false; // Prefix does not exist
            }
            node = node->children[c];
        }
        return true; // If we've traversed all characters of the prefix
    }
};
