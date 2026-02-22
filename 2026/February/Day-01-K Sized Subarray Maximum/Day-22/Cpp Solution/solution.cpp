#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int xr = 0;
        long count = 0;

        for (int i = 0; i < arr.size(); i++) {
            xr ^= arr[i];

            // If prefix XOR itself equals k
            if (xr == k)
                count++;

            // If (xr ^ k) exists in map
            if (freq.find(xr ^ k) != freq.end())
                count += freq[xr ^ k];

            freq[xr]++;
        }

        return count;
    }
};
