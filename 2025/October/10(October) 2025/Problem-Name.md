**## ZigZag Tree Traversal**

**Difficulty:** Medium
**Accuracy:** 54.05%
**Submissions:** 186K+
**Points:** 4
**Average Time:** 30m

---

### 🧩 Problem Statement

Given the root of a binary tree, find the **zig-zag level order traversal** of the binary tree.

**Note:** In zig-zag traversal, we traverse nodes from left to right for odd-numbered levels, and from right to left for even-numbered levels.

---

### 💡 Examples

#### Example 1:

**Input:**
root = [1, 2, 3, 4, 5, 6, 7]

**Output:**
[1, 3, 2, 4, 5, 6, 7]

**Explanation:**
Level 1 (left to right): [1]
Level 2 (right to left): [3, 2]
Level 3 (left to right): [4, 5, 6, 7]
Final result: [1, 3, 2, 4, 5, 6, 7]

---

#### Example 2:

**Input:**
root = [7, 9, 7, 8, 8, 6, N, 10, 9]

**Output:**
[7, 7, 9, 8, 8, 6, 9, 10]

**Explanation:**
Level 1 (left to right): [7]
Level 2 (right to left): [7, 9]
Level 3 (left to right): [8, 8, 6]
Level 4 (right to left): [9, 10]
Final result: [7, 7, 9, 8, 8, 6, 9, 10]

---

### ⚙️ Constraints

* 1 ≤ number of nodes ≤ 10⁵
* 1 ≤ node->data ≤ 10⁵

---

### 🧠 Approach

We perform a **level order traversal (BFS)** using a queue.
At each level, we store the node values in a temporary vector.
If the level is even-numbered, we **reverse** the vector before appending it to the result.

---

### 🚀 Steps

1. Initialize a queue with the root node.
2. Use a boolean flag `leftToRight` to track the direction.
3. For each level:

   * Get the size of the current level.
   * Traverse all nodes, storing them in a temporary vector.
   * Reverse the vector if direction is right-to-left.
   * Append the level's data to the final result.
   * Toggle the direction flag.

---

### 💻 Code Implementation (C++)

```cpp
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->data;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            for (int val : level)
                result.push_back(val);
            
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};
```

---

### ⏱️ Complexity Analysis

* **Time Complexity:** O(N) — Every node is visited once.
* **Space Complexity:** O(N) — Queue + temporary level vector.

---

### 🏁 Summary

✅ Perform level order traversal using a queue.
✅ Reverse every alternate level.
✅ Append results in order to form the zig-zag traversal output.
