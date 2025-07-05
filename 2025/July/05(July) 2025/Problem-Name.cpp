class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int max_score = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            int a = arr[i], b = arr[i+1];
            max_score = max(max_score, a + b);
        }
        return max_score;
    }
};
