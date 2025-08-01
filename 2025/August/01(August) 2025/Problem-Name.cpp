class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp{{0, 1}};
        for (string& s : arr) {
            int score = 0;
            for (char c : s) score += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : -1;
            res += mp[sum += score]++;
        }
        return res;
    }
};
