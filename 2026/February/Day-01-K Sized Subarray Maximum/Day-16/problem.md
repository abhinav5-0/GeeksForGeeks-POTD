# Meeting Rooms

**Difficulty:** Easy
**Accuracy:** 65.12%
**Submissions:** 38K+
**Points:** 2

---

## Problem Statement

Given a 2D array `arr[][]`, where:

* `arr[i][0]` represents the **starting time** of the ith meeting.
* `arr[i][1]` represents the **ending time** of the ith meeting.

The task is to check if it is possible for a person to attend **all meetings** such that they can attend **only one meeting at a time**.

---

## Note

A person can attend a meeting if its starting time is **greater than or equal to** the ending time of the previous meeting.

---

## Examples

### Example 1

**Input:**

```
arr[][] = [[1, 4], [10, 15], [7, 10]]
```

**Output:**

```
true
```

**Explanation:**
Since all the meetings are held at different times, it is possible to attend all the meetings.

---

### Example 2

**Input:**

```
arr[][] = [[2, 4], [9, 12], [6, 10]]
```

**Output:**

```
false
```

**Explanation:**
Since the second and third meetings overlap, a person cannot attend all the meetings.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i][j] ≤ 2 * 10^6`

---

## Expected Approach

1. Sort the meetings based on their starting time.
2. Traverse through the sorted meetings.
3. If the starting time of the current meeting is less than the ending time of the previous meeting, return `false`.
4. If no overlaps are found, return `true`.

---

## Function Signature (C++)

```cpp
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
    }
};
```

---

## Time Complexity

* **O(n log n)** (due to sorting)

## Space Complexity

* **O(1)** (if sorting in-place) or **O(n)** depending on sorting implementation
