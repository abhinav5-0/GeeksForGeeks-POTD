# 🔥 Burning Tree

## 🧩 Problem Statement

Given the **root** of a binary tree and a **target node**, determine the **minimum time** required to burn the entire tree if the target node is set on fire.

* In **1 second**, fire spreads from a node to:

  * its **left child**
  * its **right child**
  * its **parent**

> 🔹 The tree contains **unique values**.

---

## 📥 Examples

### Example 1

```
Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
```

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

**Output:**

```
3
```

**Explanation:**

* t = 0 → Node 2 burns
* t = 1 → Nodes 4, 5, 1 burn
* t = 2 → Node 3 burns
* t = 3 → Nodes 6, 7 burn

---

### Example 2

```
Input: root = [1, 2, 3, 4, 5, N, 7, 8, N, N, 10], target = 10
```

```
        1
      /   \
     2     3
    / \     \
   4   5     7
  /     \
 8       10
```

**Output:**

```
5
```

**Explanation:**

* t = 0 → Node 10 burns
* t = 1 → Node 5 burns
* t = 2 → Node 2 burns
* t = 3 → Nodes 1 and 4 burn
* t = 4 → Nodes 3 and 8 burn
* t = 5 → Node 7 burns

---

## ⚙️ Approach

### 🔑 Key Idea

Treat the binary tree as an **undirected graph**:

* Each node connects to:

  * left child
  * right child
  * parent

Then perform **BFS (level-order traversal)** starting from the target node.

---

### 🧠 Steps

1. **Create Parent Mapping**

   * Traverse tree and store parent of each node.

2. **Find Target Node**

   * While building parent map.

3. **Run BFS from Target**

   * Use queue and visited set.
   * Spread fire in all directions.

4. **Count Levels**

   * Each BFS level = 1 second.

---

## ⏱️ Complexity

* **Time:** `O(N)`
* **Space:** `O(N)`

---

## 🚀 Notes

* Important to track **visited nodes** to avoid cycles.
* Parent mapping is required because tree doesn't have parent pointers.

---

## 🏁 Summary

* Convert tree → graph
* Start BFS from target
* Count levels → answer

---

Happy Coding! 🎯
