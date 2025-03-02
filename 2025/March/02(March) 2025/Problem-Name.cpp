#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices of useful elements

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove smaller elements as they are useless
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            // Add the current element index
            dq.push_back(i);

            // Store max for the current window (only when i >= k - 1)
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }
        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int val : res)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
