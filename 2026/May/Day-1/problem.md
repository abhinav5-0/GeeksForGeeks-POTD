# Kth Largest in a Stream

## 🧩 Problem Statement

Given an input stream `arr[]` of `n` integers, find the **Kth largest element** after each insertion.

* If the Kth largest element does not exist, return `-1` for that step.
* Return a list of size `n` where each element represents the Kth largest element after that insertion.

---

## 📥 Examples

### Example 1

```
Input: arr[] = [1, 2, 3, 4, 5, 6], k = 4
Output: [-1, -1, -1, 1, 2, 3]
```

### Example 2

```
Input: arr[] = [3, 2, 1, 3, 3], k = 2
Output: [-1, 2, 2, 3, 3]
```

---

## 🚀 Approach (Min Heap)

* Use a **min heap (priority queue)** of size `k`
* Keep inserting elements into the heap
* If heap size exceeds `k`, remove the smallest element
* The top of the heap will always give the Kth largest element

### Steps:

1. Create a min heap
2. Traverse the array
3. Push current element into heap
4. If heap size > k → pop smallest
5. If heap size < k → answer = -1
6. Else → answer = heap top

---

## ⏱️ Complexity

* **Time Complexity:** `O(n log k)`
* **Space Complexity:** `O(k)`

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> result;
        
        for(int x : arr) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
            
            if(pq.size() < k)
                result.push_back(-1);
            else
                result.push_back(pq.top());
        }
        
        return result;
    }
};
```

---

## 💻 Java Solution

```java
import java.util.*;

class Solution {
    public ArrayList<Integer> kthLargest(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        ArrayList<Integer> result = new ArrayList<>();

        for(int x : arr) {
            pq.offer(x);

            if(pq.size() > k)
                pq.poll();

            if(pq.size() < k)
                result.add(-1);
            else
                result.add(pq.peek());
        }

        return result;
    }
}
```

---

## 💻 Python Solution

```python
import heapq

def kthLargest(arr, k):
    pq = []
    result = []
    
    for x in arr:
        heapq.heappush(pq, x)
        
        if len(pq) > k:
            heapq.heappop(pq)
        
        if len(pq) < k:
            result.append(-1)
        else:
            result.append(pq[0])
    
    return result
```

---

## 🧠 Key Insight

* We only care about **top k elements**, not the entire array
* Min heap helps efficiently maintain the kth largest element

---

## ✅ Summary

| Step     | Action                 |
| -------- | ---------------------- |
| Insert   | Push element into heap |
| Maintain | Keep heap size = k     |
| Output   | Heap top = kth largest |

---

Happy Coding 🚀
