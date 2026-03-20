# Predecessor and Successor

**Difficulty:** Medium
**Accuracy:** 47.24%
**Submissions:** 188K+
**Points:** 4

---

## Problem Statement

You are given the root of a **Binary Search Tree (BST)** and an integer `key`.
You need to find the **inorder predecessor** and **inorder successor** of the given key.

* If predecessor or successor does not exist, return `NULL`.

---

## Note

* In **inorder traversal**:

  * The number just **smaller** than the target is the **predecessor**
  * The number just **greater** than the target is the **successor**

---

## Examples

### Example 1

**Input:**

```
root = [50, 30, 70, 20, 40, 60, 80], key = 65
```

**Output:**

```
[60, 70]
```

**Explanation:**

* Predecessor of `65` = `60`
* Successor of `65` = `70`

---

### Example 2

**Input:**

```
root = [8, 1, 9, N, 4, N, 10, 3], key = 8
```

**Output:**

```
[4, 9]
```

**Explanation:**

* Predecessor of `8` = `4`
* Successor of `8` = `9`

---

## Constraints

* `1 ≤ number of nodes ≤ 10^5`
* `0 ≤ node->data ≤ 10^6`
* `1 ≤ key ≤ 10^6`

---

## Approach (Efficient BST Traversal)

* Start from root
* If `key > root->data`

  * Store root as predecessor
  * Move to right subtree
* Else

  * Store root as successor
  * Move to left subtree

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;

        while (root) {
            if (root->data < key) {
                pre = root;
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }

        return {
            pre ? pre->data : -1,
            suc ? suc->data : -1
        };
    }
};
```

---

## Java Solution

```java
class Solution {
    public ArrayList<Integer> findPreSuc(Node root, int key) {
        Node pre = null, suc = null;

        while (root != null) {
            if (root.data < key) {
                pre = root;
                root = root.right;
            } else {
                suc = root;
                root = root.left;
            }
        }

        ArrayList<Integer> res = new ArrayList<>();
        res.add(pre != null ? pre.data : -1);
        res.add(suc != null ? suc.data : -1);
        return res;
    }
}
```

---

## Python Solution

```python
class Solution:
    def findPreSuc(self, root, key):
        pre, suc = None, None

        while root:
            if root.data < key:
                pre = root
                root = root.right
            else:
                suc = root
                root = root.left

        return [
            pre.data if pre else -1,
            suc.data if suc else -1
        ]
```

---

## Complexity

* **Time Complexity:** `O(H)` (Height of BST)
* **Space Complexity:** `O(1)`
