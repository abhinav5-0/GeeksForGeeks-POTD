class Solution {
public:
struct Trie {
Trie* child[2];
int cnt;
Trie() {
child[0] = child[1] = nullptr;
cnt = 0;
}
};


void insert(Trie* root, int num) {
for (int i = 15; i >= 0; i--) {
int b = (num >> i) & 1;
if (!root->child[b]) root->child[b] = new Trie();
root = root->child[b];
root->cnt++;
}
}


int query(Trie* root, int num, int k) {
int ans = 0;
for (int i = 15; i >= 0; i--) {
if (!root) break;
int b = (num >> i) & 1;
int kb = (k >> i) & 1;


if (kb == 1) {
// Add counts from same-bit branch
if (root->child[b]) ans += root->child[b]->cnt;
// Move to opposite branch
root = root->child[b ^ 1];
} else {
// Must match exactly
root = root->child[b];
}
}
return ans;
}


int cntPairs(vector<int>& arr, int k) {
Trie* root = new Trie();
int count = 0;


for (int num : arr) {
count += query(root, num, k);
insert(root, num);
}
return count;
}
};
