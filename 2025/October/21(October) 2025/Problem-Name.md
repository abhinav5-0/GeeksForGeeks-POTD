## Top K Frequent Elements in Array

**Difficulty:** Medium
**Accuracy:** 40.23%
**Points:** 4
**Average Time:** 30 mins

---

### 🧠 Problem Statement

Given a non-empty integer array `arr[]`, your task is to find and return the **top K elements** which have the **highest frequency** in the array.

If two numbers have the same frequency, the **larger number** should be given **higher priority**.

---

### 📥 Input

* `arr[]`: integer array of size N
* `k`: integer (number of top frequent elements)

### 📤 Output

* Return a vector of integers representing the top K frequent elements.

---

### 📘 Example 1

**Input:**
`arr[] = [3, 1, 4, 4, 5, 2, 6, 1], k = 2`

**Output:**
`[4, 1]`

**Explanation:**
Frequency of 4 is 2 and frequency of 1 is 2. Since both have the same frequency, the larger number (4) is given priority.

---

### 📘 Example 2

**Input:**
`arr[] = [7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9], k = 4`

**Output:**
`[5, 11, 7, 10]`

**Explanation:**
Frequencies are: 5 → 3, 11 → 2, 7 → 2, 10 → 1.
Top 4 elements are selected in this order.

---

### ⚙️ Constraints

```
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5
1 ≤ k ≤ number of distinct elements
```

---

### 💡 Approach

1. Count frequency of each element using a hash map.
2. Use a **max-heap** (priority queue) with a custom comparator:

   * Higher frequency first.
   * If equal frequency, larger number first.
3. Extract top K elements from the heap.

---

### 🧩 Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first < b.first;  // larger number first if freq same
            return a.second < b.second;    // higher frequency first
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (auto &p : freq) {
            pq.push({p.first, p.second});
        }
        
        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;
    vector<int> ans = obj.topKFreq(arr, k);
    
    for (int x : ans) cout << x << " ";
    return 0;
}
```

---

### ⏱️ Time Complexity

* Frequency Map: **O(N)**
* Heap Operations: **O(M log M)** where M = distinct elements
* Extraction: **O(K log M)**

✅ **Overall:** `O(N + M log M)`

### 💾 Space Complexity

`O(M)` for storing frequencies and heap.

---

### 🏁 Output for Sample Input

**Input:**
`arr = [3, 1, 4, 4, 5, 2, 6, 1], k = 2`
**Output:**
`4 1`
