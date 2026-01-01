# 🧩 Intersection in Y Shaped Lists

**Difficulty:** Medium
**Accuracy:** 44.67%
**Points:** 4

---

## 📄 Problem Statement

You are given the heads of two non-empty singly linked lists `head1` and `head2` that intersect at a certain point.

Return the **node** at which these two linked lists intersect.

> 🔒 It is guaranteed that the intersected node **always exists**.

The lists form a **Y-shaped structure**, where the tail part is common to both lists.

---

## 💡 Approach / Explanation

We use the **two-pointer technique** without using extra space.

### Key Idea:

* Traverse both linked lists using two pointers `p1` and `p2`
* When `p1` reaches the end of list1, move it to `head2`
* When `p2` reaches the end of list2, move it to `head1`

By doing this:

* Both pointers traverse **equal total length**
* They will meet exactly at the **intersection node**

This avoids length calculation and extra memory.

---

## ⚙️ Algorithm Steps

1. Initialize two pointers `p1 = head1` and `p2 = head2`
2. Move both pointers one step at a time
3. If `p1` becomes NULL, redirect it to `head2`
4. If `p2` becomes NULL, redirect it to `head1`
5. Continue until `p1 == p2`
6. Return `p1` (intersection node)

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n + m)
* **Space Complexity:** O(1)

---

## ⚠️ Edge Cases Considered

* Intersection at the first node
* Different list lengths
* Guaranteed intersection (no NULL result)

---

## 🧠 Key Takeaways

* Two-pointer technique can equalize path lengths
* No need to calculate lengths or use hashing
* Clean and optimal solution

---

## 🔗 Reference

* GeeksforGeeks Problem of the Day

---

⭐ *If this explanation helped you, consider starring the repository!*

---

## 💻 cpp/solution.cpp

```cpp
class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* p1 = head1;
        Node* p2 = head2;

        // Traverse until both pointers meet
        while (p1 != p2) {
            p1 = (p1 == NULL) ? head2 : p1->next;
            p2 = (p2 == NULL) ? head1 : p2->next;
        }

        // p1 (or p2) is the intersection point
        return p1;
    }
};
```

---

## ☕ java/Solution.java

```java
class Solution {
    public static Node intersectPoint(Node head1, Node head2) {
        Node p1 = head1;
        Node p2 = head2;

        // Traverse until both pointers meet
        while (p1 != p2) {
            p1 = (p1 == null) ? head2 : p1.next;
            p2 = (p2 == null) ? head1 : p2.next;
        }

        // p1 (or p2) is the intersection point
        return p1;
    }
}
```

---

## 🐍 python/solution.py

```python
class Solution:
    def intersectPoint(self, head1, head2):
        p1 = head1
        p2 = head2

        # Traverse until both pointers meet
        while p1 != p2:
            p1 = head2 if p1 is None else p1.next
            p2 = head1 if p2 is None else p2.next

        # p1 (or p2) is the intersection point
        return p1
```

---

🔥 *Day-01 completed with a clean and optimal multi-language approach.*
