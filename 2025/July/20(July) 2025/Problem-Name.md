# Problem: Count Numbers Containing Specific Digits

**Difficulty:** Medium
**Accuracy:** 63.36%
**Submissions:** 9K+
**Points:** 4
**Average Time:** 25 minutes

## Problem Statement

You are given:

* An integer `n` representing the number of digits in a number.
* An array `arr[]` containing digits from 0 to 9.

You have to **count how many `n`-digit positive integers** can be formed such that **at least one digit** from the array `arr[]` appears in the number.

### Input

* An integer `n` (1 ≤ n ≤ 9)
* An array `arr[]` of size between 1 and 10, where each element is a digit from 0 to 9.

### Output

* Return the count of valid `n`-digit numbers that contain **at least one digit from** `arr[]`.

### Examples

#### Example 1:

**Input:**

```
n = 1
arr[] = [1, 2, 3]
```

**Output:**

```
3
```

**Explanation:** Only the single-digit numbers \[1, 2, 3] satisfy the condition.

#### Example 2:

**Input:**

```
n = 2
arr[] = [3, 5]
```

**Output:**

```
34
```

**Explanation:** There are 34 two-digit numbers which contain at least one of \[3, 5].

### Constraints

* 1 ≤ n ≤ 9
* 1 ≤ arr.size() ≤ 10
* 0 ≤ arr\[i] ≤ 9

### Function Signature

```cpp
class Solution {
  public:
    int countValid(int n, vector<int>& arr);
};
```

### Notes

* The result must count only **positive n-digit numbers**.
* Leading zeros are not allowed in the final numbers.
* A brute-force solution works for small `n` (e.g., n ≤ 5), but for higher values of `n`, consider optimizing using techniques like **Digit Dynamic Programming (Digit DP)**.
