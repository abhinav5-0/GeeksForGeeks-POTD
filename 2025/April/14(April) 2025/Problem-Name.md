## Problem: Alien Dictionary

### Difficulty: Hard

### Problem Statement:
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of `words[]` from the alien language's dictionary, where the words are claimed to be sorted lexicographically according to the language's rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string `a` is lexicographically smaller than a string `b` if, at the first position where they differ, the character in `a` appears earlier in the alien language than the corresponding character in `b`. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

### Input Format:
- An integer `t` denoting the number of test cases.
- For each test case, a space-separated list of words representing the alien language dictionary.

### Output Format:
- For each test case, output `true` if the order returned by your function is valid according to the alien dictionary rules, otherwise output `false`.

### Constraints:
- 1 <= words.length <= 500
- 1 <= words[i].length <= 100
- words[i] consists only of lowercase English letters

### Examples:

#### Input:
```plaintext
words[] = ["baa", "abcd", "abca", "cab", "cad"]
```
#### Output:
```plaintext
true
```
#### Explanation:
A possible correct order of letters in the alien dictionary is "bdac".
- The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
- The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
- The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
- The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.

So, 'b' → 'd' → 'a' → 'c' is a valid ordering.

#### Input:
```plaintext
words[] = ["caa", "aaa", "aab"]
```
#### Output:
```plaintext
true
```
#### Explanation:
A possible correct order of letters in the alien dictionary is "cab".
- The pair "caa" and "aaa" suggests 'c' appears before 'a'.
- The pair "aaa" and "aab" suggests 'a' appears before 'b'.

#### Input:
```plaintext
words[] = ["ab", "cd", "ef", "ad"]
```
#### Output:
```plaintext
""
```
#### Explanation:
No valid ordering of letters is possible due to a cycle in the dependency graph.

### Notes:
- Use graph construction and topological sorting to solve the problem.
- Detect prefix problems (e.g., "abc" and "ab").
- Implement Kahn's Algorithm (BFS) or DFS-based topological sort.

### Expected Function Signature:
```cpp
string findOrder(vector<string> &words);
```

The implementation should be validated using a provided `validate()` function to verify correctness of the result.

