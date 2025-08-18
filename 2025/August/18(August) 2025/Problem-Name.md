# H-Index

**Difficulty:** Medium  
**Accuracy:** 53.4%  
**Submissions:** 45K+  
**Points:** 4  

---

## Problem Statement
You are given an array `citations[]`, where each element `citations[i]` represents the number of citations received by the *i-th* paper of a researcher. You have to calculate the researcher’s **H-index**.

The **H-index** is defined as the maximum value `H`, such that the researcher has published at least `H` papers, and all those papers have citation value greater than or equal to `H`.

---

## Examples

### Example 1
**Input:**
```cpp
citations[] = [3, 0, 5, 3, 0]
```
**Output:**
```
3
```
**Explanation:**
There are at least 3 papers with citation counts of 3, 5, and 3, all having citations greater than or equal to 3.

---

### Example 2
**Input:**
```cpp
citations[] = [5, 1, 2, 4, 1]
```
**Output:**
```
2
```
**Explanation:**
There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.

---

### Example 3
**Input:**
```cpp
citations[] = [0, 0]
```
**Output:**
```
0
```
**Explanation:**
The H-index is 0 because there are no papers with at least 1 citation.

---

## Constraints
- `1 ≤ citations.size() ≤ 10^6`
- `0 ≤ citations[i] ≤ 10^6`

---

## Approach

### Sorting-based Solution (O(n log n))
1. Sort the array `citations` in descending order.
2. Traverse the sorted array, checking how many papers have at least `i+1` citations.
3. The maximum valid `i+1` is the H-index.

---

## C++ Solution
```cpp
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>()); // sort in descending order
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                h = i + 1;
            } else {
                break;
            }
        }
        return h;
    }
};
```

---

## Time Complexity
- Sorting: **O(n log n)**
- Traversal: **O(n)**
- **Total:** O(n log n)

## Space Complexity
- **O(1)** (in-place sorting)

---
