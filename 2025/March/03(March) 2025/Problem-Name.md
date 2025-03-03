## Longest Bounded-Difference Subarray

### Problem Statement
Given an array of positive integers `arr[]` and a non-negative integer `x`, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than `x`.
If multiple such subarrays exist, return the one that starts at the smallest index.

### Examples

#### Example 1:
**Input:**  
`arr[] = [8, 4, 2, 6, 7], x = 4`

**Output:**  
`[4, 2, 6]`

**Explanation:**  
The sub-array `[4, 2, 6]` (indices 1 to 3) has all elements satisfying the given condition.

#### Example 2:
**Input:**  
`arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5`

**Output:**  
`[2, 4, 7, 2]`

**Explanation:**  
The sub-array `[2, 4, 7, 2]` (indices 3 to 6) satisfies the condition.

---

### Constraints
- \(1 \leq arr.size() \leq 10^5\)
- \(1 \leq arr[i] \leq 10^9\)
- \(0 \leq x \leq 10^9\)

---

### Approach
To solve this problem efficiently, we use the **sliding window technique** with an **ordered multiset** to keep track of the elements within the window.

#### **Algorithm:**
1. Use two pointers (`left` and `right`) to maintain a valid window.
2. Insert elements into a `multiset` while expanding `right`.
3. If the difference between the maximum and minimum element in the window exceeds `x`, shrink the window from `left`.
4. Keep track of the maximum window size found so far.
5. Extract and return the longest valid subarray.

---

### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0, startIdx = 0;
        multiset<int> window;
        
        while (right < n) {
            window.insert(arr[right]);
            
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                left++;
            }
            
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }
            
            right++;
        }
        
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        
        int k;
        cin >> k;
        cin.ignore();
        
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---

### **Complexity Analysis**
- **Time Complexity:** \(O(n \log n)\) due to `multiset` operations (insertions and deletions).
- **Space Complexity:** \(O(n)\) for storing elements in the `multiset`.

---

### **Key Takeaways**
✅ Efficient **sliding window approach** with ordered set operations.  
✅ **Handles large constraints** effectively with optimal complexity.  
✅ Returns the **smallest index subarray** in case of ties.

---

🚀 **Optimized solution for real-world scenarios!**

