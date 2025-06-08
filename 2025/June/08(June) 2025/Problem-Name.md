# Sum-string

**Difficulty:** Hard
**Accuracy:** 50.56%
**Submissions:** 37K+
**Points:** 8

## Problem Statement

Given a string `s` consisting of digits, determine whether it can be classified as a **sum-string**.

A **sum-string** is a string that can be split into more than two non-empty substrings such that:

* The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).
* This condition must apply recursively to the substrings before it.
* The rightmost substring (and any number in the sum) must **not** contain leading zeroes, unless the number is exactly `'0'`.

## Examples

### Example 1:

**Input:** `s = "12243660"`
**Output:** `true`
**Explanation:** The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
`36 = 12 + 24`, and `60 = 24 + 36`. Hence, it is a sum-string.

### Example 2:

**Input:** `s = "1111112223"`
**Output:** `true`
**Explanation:** Split the string as {"1", "111", "112", "223"}, where:
`112 = 1 + 111` and `223 = 111 + 112`. Hence, it follows the sum-string rule.

### Example 3:

**Input:** `s = "123456"`
**Output:** `false`
**Explanation:** There is no valid split of the string such that each part satisfies the sum-string property recursively.

## Constraints

* `1 ≤ s.size() ≤ 100`
* String consists of characters from `'0'` to `'9'`.

## Function Signature

```cpp
class Solution {
  public:
    bool isSumString(string &s);
};
```

## Notes

* Try all possible splits for the first two numbers.
* Recursively validate that the rest of the string can be formed using the sum of the previous two.
* Ensure there are no leading zeros in any of the numbers unless the number is exactly "0".
