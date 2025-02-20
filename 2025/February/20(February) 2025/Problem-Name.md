# Median in a Stream

## Problem Statement
Given a data stream `arr[]` where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

### Median Calculation Rules:
1. If the data set has an **odd** number of elements, the median is the middle element.
2. If the data set has an **even** number of elements, the median is the arithmetic mean of the two middle values.

## Example
### **Input:**
```cpp
arr[] = [5, 15, 1, 3, 2, 8]
```
### **Output:**
```cpp
[5.0, 10.0, 5.0, 4.0, 3.0, 4.0]
```
### **Explanation:**
| Number Inserted | Max Heap | Min Heap | Median |
|---|---|---|---|
| **5** | [5] | [] | 5.0 |
| **15** | [5] | [15] | (5+15)/2 = 10.0 |
| **1** | [1,5] | [15] | 5.0 |
| **3** | [1,3] | [5,15] | (3+5)/2 = 4.0 |
| **2** | [1,2,3] | [5,15] | 3.0 |
| **8** | [1,2,3] | [5,8,15] | (3+5)/2 = 4.0 |

---

## Approach
The problem is efficiently solved using **two heaps (priority queues):**
- A **max heap** (to store the smaller half of the numbers).
- A **min heap** (to store the larger half of the numbers).

### **Algorithm:**
1. Insert the incoming number into one of the heaps:
   - If the number is **less than or equal** to the max heap's top, push it into the **max heap**.
   - Otherwise, push it into the **min heap**.
2. Balance the heaps:
   - The max heap can have at most **one more element** than the min heap.
   - If the max heap has two more elements than the min heap, transfer the top element from max heap to min heap.
   - If the min heap has more elements than max heap, transfer the top element from min heap to max heap.
3. Compute the median:
   - If both heaps are **balanced**, the median is the **average of the tops** of both heaps.
   - Otherwise, the median is the **top of the max heap**.

---

## Code Implementation
### **C++ Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        priority_queue<int> maxHeap; // Max heap for smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for larger half

        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (maxHeap.size() == minHeap.size()) {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                result.push_back(maxHeap.top());
            }
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
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (double &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
```

---

## Complexity Analysis
- **Insertion into a heap:** `O(log N)`
- **Balancing the heaps:** `O(log N)`
- **Finding the median:** `O(1)`
- **Total Complexity for N elements:** `O(N log N)`, which is efficient for `N ≤ 10^5`.

---

## Edge Cases Considered
1. **Single element**: `[2]` → Output `[2.0]`
2. **All elements are same**: `[2,2,2,2]` → Output `[2.0, 2.0, 2.0, 2.0]`
3. **Already sorted input**: `[1,2,3,4,5]`
4. **Reverse sorted input**: `[5,4,3,2,1]`
5. **Large inputs (10^5 elements)** → Efficient handling with **O(N log N)** complexity.

---

## Alternative Approach
- **Brute Force:** Maintain a sorted list and find the median at each step using binary search or sorting.
  - **Time Complexity:** `O(N^2)` (inserting and sorting repeatedly).
  - **Not feasible for large inputs.**

Using **two heaps is the optimal approach** for real-time median calculation. 🚀

---

## Contributions
Feel free to fork this repository, make improvements, and submit a pull request!

### **Author:**
- **Name:** Abhinav Kumar
- **GitHub:** github.com/abhinav5-0



