## Problem: Substrings with Same First and Last Characters

**Difficulty:** Easy  
**Accuracy:** 50.0%  
**Submissions:** 22K+  
**Points:** 2

### Problem Statement:
Given a string `s` consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

### Input:
- A string `s` of lowercase English alphabets.

### Output:
- An integer representing the total number of substrings where the first and last characters are the same.

### Constraints:
- $1 \leq |s| \leq 10^4$
- `s` contains only lowercase English alphabets.

### Examples:

**Input:**
```
s = "abcab"
```
**Output:**
```
7
```
**Explanation:**
There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b".

**Input:**
```
s = "aba"
```
**Output:**
```
4
```
**Explanation:**
There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a".

### Efficient Approach:
1. Count the frequency of each character.
2. Use the formula: `freq * (freq + 1) / 2` for each character.
3. Sum the results to get the total count.

### Time Complexity:
- **O(n)**, where `n` is the length of the string.

### Space Complexity:
- **O(1)**, using a fixed array of size 26.
