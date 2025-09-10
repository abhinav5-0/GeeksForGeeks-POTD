class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> rightMaxIdx(n);
        
        // last element is its own max
        rightMaxIdx[n-1] = n-1;
        
        // Fill rightMaxIdx array
        for (int i = n-2; i >= 0; i--) {
            if (s[i] > s[rightMaxIdx[i+1]]) {
                rightMaxIdx[i] = i;
            } else {
                rightMaxIdx[i] = rightMaxIdx[i+1];
            }
        }
        
        // Find first place where swap is beneficial
        for (int i = 0; i < n; i++) {
            if (s[i] < s[rightMaxIdx[i]]) {
                swap(s[i], s[rightMaxIdx[i]]);
                break; // only one swap allowed
            }
        }
        
        return s;
    }
};
