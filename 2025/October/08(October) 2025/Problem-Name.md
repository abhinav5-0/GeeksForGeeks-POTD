## Construct Tree from Preorder & Postorder

**Difficulty:** Medium
**Accuracy:** 83.25%
**Submissions:** 5K+
**Points:** 4

### Problem Statement

Given two arrays `pre[]` and `post[]` that represent the preorder and postorder traversals of a **full binary tree**, construct the binary tree and return its root.

**Note:** A Full Binary Tree is a binary tree where every node has either 0 or 2 children. The preorder and postorder traversals contain unique values, and every value present in the preorder traversal is also found in the postorder traversal.

---

### Example 1

**Input:**
`pre[] = [1, 2, 4, 8, 9, 5, 3, 6, 7]`
`post[] = [8, 9, 4, 5, 2, 6, 7, 3, 1]`

**Output:**
`[1, 2, 3, 4, 5, 6, 7, 8, 9]`

**Explanation:**
The tree structure will be:

```
        1
       / \
      2   3
     / \ / \
    4  5 6  7
   /\
  8  9
```

---

### Example 2

**Input:**
`pre[] = [1, 2, 4, 5, 3, 6, 7]`
`post[] = [4, 5, 2, 6, 7, 3, 1]`

**Output:**
`[1, 2, 3, 4, 5, 6, 7]`

**Explanation:**
The tree structure will be:

```
       1
      / \
     2   3
    / \ / \
   4  5 6  7
```

---

### Constraints

* 1 ≤ number of nodes ≤ 10^3
* 1 ≤ pre[i], post[i] ≤ 10^4

---

### Approach

1. The first element in `pre[]` is always the **root** of the tree.
2. The next element in `pre[]` (`pre[preIndex+1]`) represents the **left child** of the root.
3. Find this left child in `post[]` to determine how many nodes belong to the left subtree.
4. Recursively construct the left and right subtrees.
5. Use a hashmap to store the indices of elements in `post[]` for O(1) lookup.

---

### Time Complexity

* **O(N)** using a hashmap for `post` indices.

---

### C++ Solution

```cpp
class Solution {
  public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < post.size(); i++) {
            postIndex[post[i]] = i;
        }

        int preIndex = 0;
        return build(pre, post, postIndex, preIndex, 0, post.size() - 1);
    }

  private:
    Node* build(vector<int>& pre, vector<int>& post, unordered_map<int, int>& postIndex,
                int& preIndex, int left, int right) {
        if (preIndex >= pre.size() || left > right)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        // If single node subtree
        if (left == right || preIndex >= pre.size())
            return root;

        // Find index of next preorder element in postorder
        int mid = postIndex[pre[preIndex]];

        // Build left and right subtrees
        root->left = build(pre, post, postIndex, preIndex, left, mid);
        root->right = build(pre, post, postIndex, preIndex, mid + 1, right - 1);

        return root;
    }
};
```

---

### Verification (Level Order Traversal)

To verify the constructed tree, a level-order traversal would print:

```
[1, 2, 3, 4, 5, 6, 7, 8, 9]
```
