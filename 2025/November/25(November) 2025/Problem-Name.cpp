class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long freq = (long long)(i + 1) * (n - i);

            if(freq % 2 == 1)
                ans ^= arr[i];
        }
        return ans;
    }
};
