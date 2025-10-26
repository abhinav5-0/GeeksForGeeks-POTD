# Minimum Cost of Ropes

**Difficulty:** Medium  
**Accuracy:** 42.73%  
**Points:** 4  

---

## 🧩 Problem Statement

Given an array `arr[]` of rope lengths, connect all ropes into a single rope with the **minimum total cost**.  
The cost to connect two ropes is the **sum of their lengths**.

---

### 🔹 Examples

#### Example 1:
**Input:**  
`arr = [4, 3, 2, 6]`  

**Output:**  
`29`  

**Explanation:**  
- Connect 2 and 3 → cost = 5 → ropes = [4, 5, 6]  
- Connect 4 and 5 → cost = 9 → ropes = [6, 9]  
- Connect 6 and 9 → cost = 15 → ropes = [15]  
- **Total cost = 5 + 9 + 15 = 29**

---

#### Example 2:
**Input:**  
`arr = [4, 2, 7, 6, 9]`  

**Output:**  
`62`  

**Explanation:**  
- Connect 2 and 4 → cost = 6 → ropes = [6, 6, 7, 9]  
- Connect 6 and 6 → cost = 12 → ropes = [7, 9, 12]  
- Connect 7 and 9 → cost = 16 → ropes = [12, 16]  
- Connect 12 and 16 → cost = 28 → ropes = [28]  
- **Total cost = 6 + 12 + 16 + 28 = 62**

---

#### Example 3:
**Input:**  
`arr = [10]`  

**Output:**  
`0`  

**Explanation:**  
Only one rope, no cost required.

---

## ⚙️ Constraints

- `1 ≤ arr.size() ≤ 10^5`  
- `1 ≤ arr[i] ≤ 10^4`

---

## 🧠 Intuition

To minimize cost:
- Always connect the **two smallest ropes first**.
- After connecting them, push the resulting rope back into the collection.
- Continue until only one rope remains.

This greedy approach ensures that smaller costs are added first, leading to the minimum overall cost — similar to the **Huffman coding** concept.

---

## 💻 C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // Min-heap for rope lengths
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        int totalCost = 0;
        
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            int cost = first + second;
            totalCost += cost;
            
            pq.push(cost);
        }
        
        return totalCost;
    }
};
