# Longest Subarray with Majority Greater than K

**Difficulty:** Medium
**Accuracy:** 52.63%
**Submissions:** 31K+
**Points:** 4

---

## 📝 Problem Statement

Given an array `arr[]` and an integer `k`, the task is to find the length of the **longest subarray** in which the **count of elements greater than `k`** is **more than** the **count of elements less than or equal to `k`**.

---

## 📥 Examples

### Example 1

**Input:**

```
arr[] = [1, 2, 3, 4, 1]
k = 2
```

**Output:**

```
3
```

**Explanation:**
The subarray `[2, 3, 4]` or `[3, 4, 1]` satisfies the given condition.
There is no subarray of length 4 or 5 that satisfies the condition.
So, the answer is **3**.

---

### Example 2

**Input:**

```
arr[] = [6, 5, 3, 4]
k = 2
```

**Output:**

```
4
```

**Explanation:**
In the subarray `[6, 5, 3, 4]`, there are 4 elements greater than 2 and 0 elements less than or equal to 2.
So, it is the longest possible subarray.

---

## 📌 Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ arr[i] ≤ 10^6`
* `0 ≤ k ≤ 10^6`

---

## 💡 Hint

You can transform the array into:

* `+1` if `arr[i] > k`
* `-1` if `arr[i] <= k`

Then, the problem reduces to finding the **longest subarray with positive sum**.

---

## 🔎 Expected Approach

* Convert the array into `+1` and `-1` values.
* Use prefix sum technique.
* Use hashing or a monotonic structure to efficiently find the longest subarray with sum > 0.

**Time Complexity:** O(N)
**Auxiliary Space:** O(N)
