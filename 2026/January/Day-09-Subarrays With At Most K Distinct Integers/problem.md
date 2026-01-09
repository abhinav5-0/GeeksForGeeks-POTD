# Subarrays With At Most K Distinct Integers

## Problem Statement

You are given an array `arr[]` of positive integers and an integer `k`. Your task is to count the number of **contiguous subarrays** such that the number of **distinct integers** in each subarray is **at most `k`**.

---

## Examples

### Example 1

**Input:**

```
arr = [1, 2, 2, 3], k = 2
```

**Output:**

```
9
```

**Explanation:**
Valid subarrays are:

```
[1], [2], [2], [3], [1,2], [2,2], [2,3], [1,2,2], [2,2,3]
```

---

### Example 2

**Input:**

```
arr = [1, 1, 1], k = 1
```

**Output:**

```
6
```

---

### Example 3

**Input:**

```
arr = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
```

**Output:**

```
24
```

---

## Constraints

* `1 ≤ arr.size() ≤ 2 × 10⁴`
* `1 ≤ k ≤ 2 × 10⁴`
* `1 ≤ arr[i] ≤ 10⁹`

---

## Approach (Sliding Window + Hash Map)

This is a classic **sliding window** problem.

### Key Idea

* Use two pointers `left` and `right` to maintain a window.
* Use a hash map to store frequencies of elements in the current window.
* Expand the window by moving `right`.
* If distinct elements exceed `k`, shrink the window from the left.
* For every valid window ending at `right`, the number of subarrays added is:

  ```
  right - left + 1
  ```

---

## Algorithm Steps

1. Initialize `left = 0`, `ans = 0`
2. Use a map `freq` to store frequency of elements
3. Iterate `right` from `0` to `n-1`
4. Add `arr[right]` to map
5. While `freq.size() > k`, shrink window from left
6. Add `(right - left + 1)` to answer
7. Return `ans`

---

## Dry Run Example

For `arr = [1,2,2,3]`, `k = 2`

| Right | Window  | Distinct | Subarrays Added |
| ----- | ------- | -------- | --------------- |
| 0     | [1]     | 1        | 1               |
| 1     | [1,2]   | 2        | 2               |
| 2     | [1,2,2] | 2        | 3               |
| 3     | [2,2,3] | 2        | 3               |

Total = **9**

---

## Time & Space Complexity

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(K)` (at most `k` elements in map)

---

## C++ Implementation

```cpp
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int left = 0;
        long long ans = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;

            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]);
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
};
```

---

## Key Takeaways

* Sliding Window is ideal for subarray problems
* Count subarrays ending at `right` directly
* Avoid brute force `O(N²)` solutions

---

⭐ If this helped you, consider giving an **upvote** and saving it for revision!
