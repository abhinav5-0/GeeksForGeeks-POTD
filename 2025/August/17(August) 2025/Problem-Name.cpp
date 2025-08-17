class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // हम stable_sort use करेंगे ताकि equal differences में
        // order same रहे जैसा पहले था
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};
