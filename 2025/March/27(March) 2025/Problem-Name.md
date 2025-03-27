# Minimum Platforms Problem

## Problem Statement

You are given the arrival times `arr[]` and departure times `dep[]` of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

### Example 1:
**Input:**
```cpp
arr[] = [900, 940, 950, 1100, 1500, 1800]
dep[] = [910, 1200, 1120, 1130, 1900, 2000]

```
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Sort the arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n = arr.size();
        
        int platformCount = 1;  // At least one platform is needed
        int result = 1;
        
        int i = 1;  // Pointer for arrival times
        int j = 0;  // Pointer for departure times
        
        // Process all the trains
        while (i < n && j < n) {
            // If the next event is an arrival and it comes before the next departure
            if (arr[i] <= dep[j]) {
                platformCount++;
                i++;
            }
            // If the next event is a departure, we free a platform
            else {
                platformCount--;
                j++;
            }
            
            // Update the result with the maximum platforms required
            result = max(result, platformCount);
        }
        
        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Creating an object of Solution class and calling findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}
