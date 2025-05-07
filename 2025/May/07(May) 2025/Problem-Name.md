### 📄 Root to Leaf Paths - Problem Statement

#### 🧠 Difficulty: Medium

#### ✅ Accuracy: 43.65%

#### 📊 Submissions: 141K+

#### 🏅 Points: 4

#### ⏱ Average Time: 30 mins

---

### 💾 Problem Statement

Given a Binary Tree, find all the possible paths from the **root node to all the leaf nodes** of the binary tree.

> **Note**:
> The paths should be returned such that **paths from the left subtree are listed before paths from the right subtree** for any node.

---

### 📅 Input Format

* A binary tree represented in level order traversal.
* "N" denotes a null value (no child at that position).

---

### 📈 Output Format

* A list of lists, where each list represents a path from root to a leaf node.

---

### 🔢 Constraints

* 1 <= Number of nodes <= 10⁴
* 1 <= Node value <= 10⁴

---

### 📃 Examples

#### Example 1:

**Input:** `root[] = [1, 2, 3, 4, 5, N, N]`

**Output:** `[[1, 2, 4], [1, 2, 5], [1, 3]]`

**Explanation:**
Paths: 1 -> 2 -> 4, 1 -> 2 -> 5, 1 -> 3

---

#### Example 2:

**Input:** `root[] = [1, 2, 3]`

**Output:** `[[1, 2], [1, 3]]`

---

#### Example 3:

**Input:** `root[] = [10, 20, 30, 40, 60, N, N]`

**Output:** `[[10, 20, 40], [10, 20, 60], [10, 30]]`

---

### 🔧 Approach

* Use **Depth First Search (DFS)** recursively.
* Keep track of the current path in a vector.
* When a leaf node is reached, store the current path.
* Recurse on left and then right child to maintain the order.

---

### ⚖️ Sample Function Signature (C++)

```cpp
vector<vector<int>> Paths(Node* root);
```

---

### 📁 Related Topics

* Tree
* DFS
* Recursion
