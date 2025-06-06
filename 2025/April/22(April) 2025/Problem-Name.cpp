class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }
};
