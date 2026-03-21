# Predecessor and Successor (BST)

## Problem Statement

You are given the root of a Binary Search Tree (BST) and an integer `key`. You need to find the **inorder predecessor** and **inorder successor** of the given key.

* If the predecessor or successor does not exist, return `NULL` for that value.

### Note

* In an inorder traversal:

  * The value just **smaller** than the key is the **predecessor**.
  * The value just **greater** than the key is the **successor**.

---

## Examples

### Example 1

**Input:**
`root = [50, 30, 70, 20, 40, 60, 80], key = 65`

**Output:**
`[60, 70]`

**Explanation:**

* Predecessor of 65 = 60
* Successor of 65 = 70

---

### Example 2

**Input:**
`root = [8, 1, 9, N, 4, N, 10, 3], key = 8`

**Output:**
`[4, 9]`

**Explanation:**

* Predecessor of 8 = 4
* Successor of 8 = 9

---

## Approach

### Efficient BST Traversal (O(H))

Instead of storing inorder traversal, we can directly traverse the BST:

1. Start from root
2. If `key > root->data`

   * Update predecessor = root
   * Move right
3. Else

   * Move left

Repeat similarly for successor:

1. If `key < root->data`

   * Update successor = root
   * Move left
2. Else

   * Move right

---

## Complexity

* **Time Complexity:** O(H)
* **Space Complexity:** O(1)

(H = height of BST)

---

## C++ Code

```cpp
class Solution {
public:
    vector<int> findPreSuc(Node* root, int key) {
        Node* temp = root;
        int pre = -1, suc = -1;

        // Find predecessor
        while (temp) {
            if (key > temp->data) {
                pre = temp->data;
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        temp = root;

        // Find successor
        while (temp) {
            if (key < temp->data) {
                suc = temp->data;
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        return {pre, suc};
    }
};
```

---

## Java Code

```java
class Solution {
    public int[] findPreSuc(Node root, int key) {
        Node temp = root;
        int pre = -1, suc = -1;

        // Predecessor
        while (temp != null) {
            if (key > temp.data) {
                pre = temp.data;
                temp = temp.right;
            } else {
                temp = temp.left;
            }
        }

        temp = root;

        // Successor
        while (temp != null) {
            if (key < temp.data) {
                suc = temp.data;
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }

        return new int[]{pre, suc};
    }
}
```

---

## Python Code

```python
class Solution:
    def findPreSuc(self, root, key):
        pre, suc = -1, -1

        temp = root

        # Predecessor
        while temp:
            if key > temp.data:
                pre = temp.data
                temp = temp.right
            else:
                temp = temp.left

        temp = root

        # Successor
        while temp:
            if key < temp.data:
                suc = temp.data
                temp = temp.left
            else:
                temp = temp.right

        return [pre, suc]
```

---

## Summary

* Use BST properties for optimized traversal.
* Avoid full inorder traversal for better performance.
* Works efficiently for large trees.
