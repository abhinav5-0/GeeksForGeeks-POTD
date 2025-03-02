# K Sized Subarray Maximum

## Problem Statement
Given an array `arr[]` of integers and an integer `k`, find the maximum value for each contiguous subarray of size `k`. The output should be an array of maximum values corresponding to each contiguous subarray.

### **Examples**
#### **Example 1**
**Input:**  
```
arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]
k = 3
```
**Output:**  
```
[3, 3, 4, 5, 5, 5, 6]
```
**Explanation:**  
```
1st subarray = [1, 2, 3] -> max = 3
2nd subarray = [2, 3, 1] -> max = 3
3rd subarray = [3, 1, 4] -> max = 4
4th subarray = [1, 4, 5] -> max = 5
5th subarray = [4, 5, 2] -> max = 5
6th subarray = [5, 2, 3] -> max = 5
7th subarray = [2, 3, 6] -> max = 6
```

#### **Example 2**
**Input:**  
```
arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
k = 4
```
**Output:**  
```
[10, 10, 10, 15, 15, 90, 90]
```

#### **Example 3**
**Input:**  
```
arr[] = [5, 1, 3, 4, 2, 6]
k = 1
```
**Output:**  
```
[5, 1, 3, 4, 2, 6]
```

---

## **Optimized Approach: Sliding Window Maximum using Deque**
- Use a **deque** to store indices of array elements in decreasing order.
- The **front** of the deque contains the index of the **maximum** element for the current window.
- Remove elements from the **back** if they are **smaller** than the current element.
- Remove elements from the **front** if they are **out of the current window**.
- The **front** element of the deque is the **max** for the current window.

### **Optimized Code (Using Deque in C++)**
```cpp
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
```

---

### **Complexity Analysis**
- **Time Complexity:** `O(N)` (Each element is pushed and popped at most once)
- **Space Complexity:** `O(K)` (Deque stores at most `k` elements at any time)

---

### **Constraints:**
- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ k ≤ arr.size()`
- `0 ≤ arr[i] ≤ 10^9`

This approach is highly optimized compared to the brute-force method (`O(N*K)`). 🚀

