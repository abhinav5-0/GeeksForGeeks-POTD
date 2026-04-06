class Solution {
public:
    struct Node {
        int freq;
        Node *left, *right;
        
        Node(int f) {
            freq = f;
            left = right = NULL;
        }
    };
    
    struct cmp {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };
    
    void generateCodes(Node* root, string str, vector<string>& ans) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            ans.push_back(str);
        }
        
        generateCodes(root->left, str + "0", ans);
        generateCodes(root->right, str + "1", ans);
    }
    
    vector<string> huffmanCodes(string s, vector<int> f) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        // Create leaf nodes
        for (int i = 0; i < f.size(); i++) {
            pq.push(new Node(f[i]));
        }
        
        // Build Huffman Tree
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* newNode = new Node(left->freq + right->freq);
            newNode->left = left;
            newNode->right = right;
            
            pq.push(newNode);
        }
        
        Node* root = pq.top();
        vector<string> ans;
        
        generateCodes(root, "", ans);
        return ans;
    }
};
