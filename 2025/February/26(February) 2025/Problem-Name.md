# Maximum of Minimum for Every Window Size

## Problem Statement
Given an array of integers `arr[]`, the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from `1` to `arr.size()`.

More formally, for each window size `k`, determine the smallest element in all windows of size `k`, and then find the largest value among these minimums where `1 <= k <= arr.size()`.

### Examples
#### **Example 1:**
**Input:**
```cpp
arr[] = [10, 20, 30, 50, 10, 70, 30]
```
**Output:**
```
70 30 20 10 10 10 10
```
**Explanation:**
1. **Window size 1:** Minimums = `[10, 20, 30, 50, 10, 70, 30]` → Max = **70**
2. **Window size 2:** Minimums = `[10, 20, 30, 10, 10, 30]` → Max = **30**
3. **Window size 3:** Minimums = `[10, 20, 10, 10, 10]` → Max = **20**
4. **Window size 4:** Minimums = `[10, 10, 10, 10]` → Max = **10**
5. **Window size 5+:** All remain **10**

#### **Example 2:**
**Input:**
```cpp
arr[] = [10, 20, 30]
```
**Output:**
```
30 20 10
```

## Constraints
- `1 <= arr.size() <= 10^5`
- `1 <= arr[i] <= 10^6`

---

## Optimized Approach
### **Using Monotonic Stack**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

### **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> s;
        
        // Find previous smaller element index
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }
        
        // Clear stack for next computation
        while (!s.empty()) s.pop();
        
        // Find next smaller element index
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }
        
        // Store maximum of minimums for each window size
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            ans[windowSize] = max(ans[windowSize], arr[i]);
        }
        
        // Fill remaining entries
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        
        // Remove the first element (index 0 is unused)
        ans.erase(ans.begin());
        return ans;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
```

---

## **Explanation of the Code**
1. **Finding Previous and Next Smaller Elements**:
   - Using a **monotonic stack**, we determine the previous and next smaller element indices.
   - These indices determine the window size where an element is the **minimum**.

2. **Computing Maximum of Minimums**:
   - Each element contributes to a specific window size.
   - We store the **largest minimum value** for each window size.

3. **Filling the Remaining Entries**:
   - We ensure the array follows a **monotonic non-decreasing order**.

---

## **Time Complexity Analysis**
- **Finding Previous and Next Smaller Elements:** `O(n)`
- **Filling the Maximum of Minimums Array:** `O(n)`
- **Total Complexity:** `O(n)`

---

## **Edge Cases Considered**
✔ Single element array  
✔ Increasing & decreasing sequences  
✔ Arrays with duplicate elements  
✔ Large values of `n`  

---

## **Why is this Efficient?**
Instead of using a brute-force approach (**O(n^2)**), this method optimizes using **monotonic stack operations**, making it feasible for large inputs (**n ≤ 10^5**).

🚀 **This approach ensures an optimal and scalable solution.**

