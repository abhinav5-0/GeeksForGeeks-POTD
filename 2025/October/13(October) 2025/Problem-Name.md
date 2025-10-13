## Maximum Non-Adjacent Nodes Sum
**Difficulty:** Medium  
**Accuracy:** 55.35%  
**Submissions:** 97K+  
**Points:** 4  
**Average Time:** 45m  

---

### 🧩 Problem Statement
Given the root of a binary tree with integer values. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected — that is, if a node is included in the subset, neither its parent nor its children can be included.

---

### 📘 Examples
**Input:**  
`root = [11, 1, 2]`

**Output:**  
`11`

**Explanation:** The maximum sum is obtained by selecting the node 11.

---

**Input:**  
`root = [1, 2, 3, 4, N, 5, 6]`

**Output:**  
`16`

**Explanation:** The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected. Their total sum is 16.

---

### 🔒 Constraints
```
1 ≤ number of nodes ≤ 10^4  
1 ≤ node.data ≤ 10^5
```

---

### 💡 Approach
For each node, we have two choices:
1. **Include** the node → cannot include its children.
2. **Exclude** the node → may include or exclude its children (take the max for each).

We perform a **postorder traversal (left-right-root)** and compute:
- `include` = node value + sum of exclude values from its children
- `exclude` = max(include, exclude) for each child

Finally, return `max(include, exclude)` for the root.

---

### 🧠 Intuition
This is a **Dynamic Programming on Trees (Tree DP)** problem. Each subtree contributes two states: one when the node is included and one when it is excluded.

---

### ✅ C++ Solution
```cpp
class Solution {
  public:
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Include current node
        int include = root->data + left.second + right.second;

        // Exclude current node
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }

    int getMaxSum(Node* root) {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
```

---

### 🧮 Example Walkthrough
**Input:** `[1, 2, 3, 4, N, 5, 6]`

| Node | Include | Exclude |
|------|----------|----------|
| 4 | 4 | 0 |
| 5 | 5 | 0 |
| 6 | 6 | 0 |
| 2 | 2 | 4 |
| 3 | 3 | 11 |
| 1 | 16 | 15 |

✅ **Answer = 16**

---

### ⏱️ Complexity
- **Time Complexity:** O(N) — Each node visited once.
- **Space Complexity:** O(H) — Due to recursion stack (H = height of tree).

---

### 🏁 Key Takeaways
- Use **Tree DP** with pair-based state tracking.
- Distinguish between **include** and **exclude** states for every node.
- Efficient for large trees with up to 10⁴ nodes.
