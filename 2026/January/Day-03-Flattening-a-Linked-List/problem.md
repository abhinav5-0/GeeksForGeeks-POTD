# 🧩 Flattening a Linked List

**Difficulty:** Medium
**Accuracy:** 51.53%
**Points:** 4

---

## 📄 Problem Statement

You are given a linked list containing **n head nodes**, where each node has two pointers:

* `next` → points to the next node in the main list
* `bottom` → points to a sub-linked list where the current node is the head

Each sub-linked list and the main list are **already sorted in ascending order** based on their data.

Your task is to **flatten the linked list** so that all nodes appear in a **single sorted list**.

🔹 The final flattened list should be traversed using the **`bottom` pointer**, not the `next` pointer.

---

## 💡 Approach / Explanation

This problem can be solved by treating it as a **merge multiple sorted linked lists** problem.

### Key Idea:

* Recursively flatten the list from right to left
* Merge two sorted linked lists using the `bottom` pointer

At each step:

* Flatten the list on the right (`root->next`)
* Merge it with the current list (`root`) using standard merge logic

---

## ⚙️ Algorithm Steps

1. If the list is empty or has only one head node, return it
2. Recursively flatten the list starting from `root->next`
3. Merge the current list with the flattened right list
4. Ensure all `next` pointers are set to `NULL`
5. Return the merged list

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(N)
  *(N = total number of nodes across all sub-lists)*
* **Space Complexity:** O(1) *(excluding recursion stack)*

---

## ⚠️ Edge Cases Considered

* Empty linked list
* Only one head node
* Sub-lists of different lengths

---

## 🧠 Key Takeaways

* This problem is equivalent to merging multiple sorted linked lists
* Recursion helps simplify the flattening process
* Maintaining `bottom` pointers is crucial for final traversal

---

## 🔗 Reference

* GeeksforGeeks – Flattening a Linked List (Problem of the Day)

---

⭐ *If this explanation helped you, consider starring the repository!*

---

## 💻 cpp/solution.cpp

```cpp
class Solution {
  public:
    // Merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // important
        return result;
    }

    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL)
            return root;

        // Flatten the right side
        root->next = flatten(root->next);

        // Merge current list with flattened list
        root = merge(root, root->next);

        return root;
    }
};
```

---

🔥 *Day-03 completed with a clean recursive merge approach.*
