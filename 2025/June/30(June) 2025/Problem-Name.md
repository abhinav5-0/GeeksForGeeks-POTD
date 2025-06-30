## Max Min Height

**Difficulty:** Hard
**Accuracy:** 62.86%
**Submissions:** 19K+
**Points:** 8

### Problem Statement

Given a garden with `n` flowers planted in a row, represented by an array `arr[]`, where `arr[i]` denotes the height of the `i-th` flower. You will water them for `k` days. In one day, you can water `w` continuous flowers. Whenever you water a flower, its height increases by 1 unit. You have to **maximize the minimum height** of all flowers after `k` days of watering.

### Input

* `arr[]`: an array of integers representing the initial heights of the flowers
* `k`: an integer representing the number of days you can water
* `w`: an integer representing the number of continuous flowers you can water in one day

### Output

* Return an integer denoting the maximum possible **minimum height** of all flowers after `k` days.

### Examples

#### Example 1:

**Input:**

```
arr = [2, 3, 4, 5, 1]
k = 2
w = 2
```

**Output:**

```
2
```

**Explanation:**

```
Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]  
Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]  
Minimum height is 2.
```

#### Example 2:

**Input:**

```
arr = [5, 8]
k = 5
w = 1
```

**Output:**

```
9
```

**Explanation:**

```
Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]  
Day 5: Water the second flower -> arr becomes [9, 9]  
Minimum height is 9.
```

### Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ w ≤ arr.size()`
* `1 ≤ k ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^9`

### Function Signature

```cpp
class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w);
};
```
