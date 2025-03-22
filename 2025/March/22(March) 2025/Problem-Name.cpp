class Solution {
public:
    int maxVal(int x, int y, vector<int>& arr) {
        int prev2 = arr[x], prev1 = max(arr[x], arr[x + 1]);
        for (int j = x + 2; j <= y; j++) {
            int curr = max(arr[j] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        return max(maxVal(0, n - 2, arr), maxVal(1, n - 1, arr));
    }
};
