class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> flip(n, 0);
        int ans = 0, curr = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k)
                curr ^= flip[i - k];

            if((arr[i] ^ curr) == 0) {
                if(i + k > n)
                    return -1;

                ans++;
                curr ^= 1;
                flip[i] = 1;
            }
        }
        return ans;
    }
};
