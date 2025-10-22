## Nearly Sorted

**Difficulty:** Medium
**Accuracy:** 75.25%
**Points:** 4
**Average Time:** 30 mins

---

### 🧩 Problem Statement

Given an array `arr[]`, where each element is at most `k` positions away from its correct position in the sorted order, restore the sorted order of `arr[]` by rearranging the elements **in place**.

**Note:** Do not use any built-in `sort()` method.

---

### 📥 Input

* An integer array `arr[]`
* An integer `k` — the maximum distance any element is from its correct position

### 📤 Output

* The sorted array `arr[]`

---

### 🧠 Example 1

**Input:**
`arr[] = [2, 3, 1, 4], k = 2`

**Output:**
`[1, 2, 3, 4]`

**Explanation:**
All elements are at most `k = 2` positions away from their correct positions.
Element `1` moves from index `2` to `0`
Element `2` moves from index `0` to `1`
Element `3` moves from index `1` to `2`
Element `4` stays at index `3`

---

### 🧠 Example 2

**Input:**
`arr[] = [7, 9, 14], k = 1`

**Output:**
`[7, 9, 14]`

**Explanation:**
All elements are already in sorted order.

---

### 🔒 Constraints

```
1 ≤ arr.size() ≤ 10^6
0 ≤ k < arr.size()
1 ≤ arr[i] ≤ 10^6
```

---

### ⚙️ Approach

We know that each element is at most `k` positions away from its correct position. This suggests that the smallest element within any `k+1` consecutive elements is in its correct sorted position.

Thus, we can use a **min-heap (priority queue)** of size `k+1` to efficiently find and place elements in their correct order.

**Algorithm:**

1. Insert the first `k+1` elements into a min-heap.
2. Repeatedly extract the minimum element and place it in the sorted position.
3. Insert the next element from the array into the heap.
4. Continue until all elements are processed.
5. Finally, extract remaining elements from the heap.

**Time Complexity:** `O(n log k)`
**Space Complexity:** `O(k)`

---

### 💻 Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // Min heap to store k+1 elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = arr.size();
        int index = 0; // Position for sorted elements

        // Step 1: Push first k+1 elements into the heap
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.push(arr[i]);
        }

        // Step 2: For remaining elements, extract min and push next
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        // Step 3: Extract remaining elements from heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
```

---

### 🧾 Example Walkthrough

**Input:**
`arr = [2, 3, 1, 4], k = 2`

**Process:**

```
Heap = [1, 3, 2]
→ Pop 1 → arr[0] = 1
→ Push 4 → Heap = [2, 3, 4]
→ Pop 2 → arr[1] = 2
→ Pop 3 → arr[2] = 3
→ Pop 4 → arr[3] = 4
```

**Output:**
`[1, 2, 3, 4]`

---

### 🏁 Summary

✅ Efficient solution using Min Heap
✅ Time Complexity: `O(n log k)`
✅ Space Complexity: `O(k)`
✅ Works for large arrays up to `10^6` elements
