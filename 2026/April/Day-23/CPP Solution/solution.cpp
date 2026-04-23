class Solution {
public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        for (int x : arr) total += x;

        if (total % 2 != 0) return false;

        long long prefix = 0;
        for (int x : arr) {
            prefix += x;
            if (prefix == total / 2) return true;
        }
        return false;
    }
};
