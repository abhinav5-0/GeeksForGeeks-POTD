# Longest Subarray with Majority Greater than K

## Problem Statement

Given an array `arr[]` and an integer `k`, the task is to find the length of the longest subarray in which the count of elements greater than `k` is more than the count of elements less than or equal to `k`.

## Input

* An integer array `arr[]` of size `n`.
* An integer `k`.

## Output

* An integer representing the length of the longest subarray satisfying the condition.

## Constraints

* 1 <= arr.size() <= 10^6
* 1 <= arr\[i] <= 10^6
* 0 <= k <= 10^6

## Example 1

**Input:**

```
arr = [1, 2, 3, 4, 1]
k = 2
```

**Output:**

```
3
```

**Explanation:** The subarrays \[2, 3, 4] or \[3, 4, 1] have more elements greater than 2 than less than or equal to 2.

## Example 2

**Input:**

```
arr = [6, 5, 3, 4]
k = 2
```

**Output:**

```
4
```

**Explanation:** All elements in the array are greater than 2.

## Approach

1. Convert the original array into a new array with:

   * `+1` for elements greater than `k`
   * `-1` for elements less than or equal to `k`
2. Use prefix sums and a hashmap to find the longest subarray with a **positive prefix sum**.
3. Track the first occurrence of each prefix sum.
4. Update the maximum length when the current prefix sum is greater than 0, or when a subarray with net positive sum is found using previously stored prefix sums.

## Time and Space Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(n) (for hashmap)

## Tags

* Array
* Prefix Sum
* Hashing
* Subarray
* Sliding Window
