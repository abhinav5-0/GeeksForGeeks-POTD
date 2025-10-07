# Bottom View of Binary Tree

**Difficulty:** Medium
**Accuracy:** 54.18%
**Submissions:** 328K+
**Points:** 4
**Average Time:** 45m

---

## 🧩 Problem Statement

You are given the root of a binary tree, and your task is to return its **bottom view**.

The **bottom view** of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

**Note:** If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

---

### Example 1

**Input:**

```
root = [1, 2, 3, 4, 5, N, 6]
```

**Output:**

```
[4, 2, 5, 3, 6]
```

**Explanation:** The green nodes represent the bottom view of the binary tree.

---

### Example 2

**Input:**

```
root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
```

**Output:**

```
[5, 10, 4, 28, 25]
```

---

### Constraints

```
1 ≤ number of nodes ≤ 10^5
1 ≤ node->data ≤ 10^5
```

---

## 🧠 Intuition

* Each node has a **Horizontal Distance (HD)** from the root:

  * Root node → HD = 0
  * Left child → HD = parent HD - 1
  * Right child → HD = parent HD + 1
* The **bottom view** includes the **last node** encountered at each HD during a **level order traversal (BFS)**.

---

## ✅ Approach

1. Use a **queue** for level order traversal, storing pairs `(node, HD)`.
2. Use a **map<int, int>** to track `{HD → node->data}`.
3. During traversal:

   * Overwrite the map entry for each HD (to ensure the latest node is stored).
   * Push children into the queue with updated HD values.
4. Finally, extract map values in increasing order of HD.

---

## 💻 Code Implementation

```cpp
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        // Map to store HD -> Node data
        map<int, int> hdNodeMap;
        
        // Queue for BFS traversal
        queue<pair<Node*, int>> q;
        q.push({root, 0}); // Root has HD = 0
        
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            
            // Overwrite node data for the same HD
            hdNodeMap[hd] = node->data;
            
            if (node->left)
                q.push({node->left, hd - 1});
            
            if (node->right)
                q.push({node->right, hd + 1});
        }
        
        // Collect bottom view
        for (auto &it : hdNodeMap)
            result.push_back(it.second);
        
        return result;
    }
};
```

---

## 🔍 Example Walkthrough

**Input:**

```
root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
```

**Horizontal Distances:**

```
HD -2 → 5
HD -1 → 10
HD  0 → 4
HD  1 → 28
HD  2 → 25
```

**Output:**

```
[5, 10, 4, 28, 25]
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(N log N) — due to map insertions
* **Space Complexity:** O(N) — for queue and map

---

### ✅ Key Takeaways

* Uses **BFS traversal** to ensure correct order.
* Maintains **map for ordered HDs**.
* Overwrites entries to ensure the **bottom-most** node for each HD is captured.
