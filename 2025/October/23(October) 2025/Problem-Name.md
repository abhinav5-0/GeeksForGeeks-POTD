## K Closest Points to Origin

**Difficulty:** Medium
**Accuracy:** 62.4%
**Points:** 4

### **Problem Statement**

Given an integer `k` and an array of points `points[][]`, where each point is represented as `points[i] = [xi, yi]` on the X-Y plane, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the X-Y plane is the Euclidean distance, defined as:

[ distance = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2} ]

**Note:** You can return the `k` closest points in any order; the driver code will sort them.

Test cases are generated such that there will be a unique answer.

---

### **Examples**

**Input:**
`k = 2, points = [[1, 3], [-2, 2], [5, 8], [0, 1]]`
**Output:**
`[[-2, 2], [0, 1]]`

**Explanation:**
The Euclidean distances from the origin are:

* (1, 3) = ( \sqrt{10} )
* (-2, 2) = ( \sqrt{8} )
* (5, 8) = ( \sqrt{89} )
* (0, 1) = ( \sqrt{1} )

The two closest points to the origin are `[-2, 2]` and `[0, 1]`.

---

**Input:**
`k = 1, points = [[2, 4], [-1, -1], [0, 0]]`
**Output:**
`[[0, 0]]`

**Explanation:**
Distances from the origin are:

* (2, 4) = ( \sqrt{20} )
* (-1, -1) = ( \sqrt{2} )
* (0, 0) = ( \sqrt{0} )

The closest point to origin is `(0, 0)`.

---

### **Constraints**

* ( 1 \leq k \leq points.size() \leq 10^5 )
* ( -3 \times 10^4 \leq x_i, y_i \leq 3 \times 10^4 )

---

### **Approach** ✅

1. Compute the **squared distance** for each point from the origin:
   [ dist = x^2 + y^2 ]
2. Use a **max-heap (priority queue)** to keep the `k` closest points.

   * Push `(distance, point)` into the heap.
   * If heap size exceeds `k`, remove the farthest point.
3. Extract points from the heap.

---

### **Complexity Analysis**

* **Time Complexity:** ( O(n \log k) )
* **Space Complexity:** ( O(k) )

---

### **C++ Implementation**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store (distance, point)
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y; // squared distance

            // Push current point into heap
            maxHeap.push({dist, {x, y}});

            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract k closest points from heap
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto it = maxHeap.top();
            maxHeap.pop();
            ans.push_back({it.second.first, it.second.second});
        }

        return ans;
    }
};
```

---

### **Example Walkthrough**

**Input:**
`k = 2, points = [[1, 3], [-2, 2], [5, 8], [0, 1]]`

**Distances:** `[10, 8, 89, 1]`
**Two smallest:** `8, 1`  → points `[-2, 2]`, `[0, 1]`

**Output:**
`[[-2, 2], [0, 1]]`
