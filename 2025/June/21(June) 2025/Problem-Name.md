# Police and Thieves

**Difficulty:** Medium  
**Accuracy:** 34.03%  
**Submissions:** 38K+  
**Points:** 4

## Problem Statement

Given an array `arr[]`, where each element contains either a `'P'` for policeman or a `'T'` for thief. Find the **maximum number of thieves that can be caught** by the police. 

### Conditions:
- Each policeman can catch only **one** thief.
- A policeman **cannot catch a thief who is more than `k` units away** from him.

## Examples

### Example 1:
**Input:**
```cpp
arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
```
**Output:**
```
2
```
**Explanation:**
Maximum 2 thieves can be caught. First policeman catches the first thief, and second policeman can catch either the second or third thief.

### Example 2:
**Input:**
```cpp
arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
```
**Output:**
```
3
```
**Explanation:**
Maximum 3 thieves can be caught.

## Constraints
- `1 ≤ arr.size() ≤ 10^5`
- `1 ≤ k ≤ 1000`
- `arr[i] = 'P'` or `'T'`

---

## C++ Function Signature
```cpp
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
    }
};
```

---

## Suggested Approach
1. Use two queues to store indices of police and thieves.
2. Traverse the array, populating the queues.
3. Try to match the nearest thief and policeman under the distance constraint `k`.
4. Count the successful matches.

---

## Tags
`Greedy` `Two Pointers` `Queue`
