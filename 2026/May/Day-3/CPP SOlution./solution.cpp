class Solution {
  public:
    static bool cmp(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        
        // Descending order of set bits
        if (countA != countB)
            return countA > countB;
        
        return false; // maintain stable order
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        stable_sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
