# Trie Implementation Problem

## Problem Statement

You need to implement a `Trie` data structure and complete the following functions:

### Function 1: `insert(word)`
- **Input**: A string `word` of length `n`.
- **Output**: Inserts `word` into the Trie.

### Function 2: `search(word)`
- **Input**: A string `word` of length `n`.
- **Output**: Returns `true` if the word `word` exists in the Trie, and `false` otherwise.

### Function 3: `isPrefix(word)`
- **Input**: A string `word` of length `n`.
- **Output**: Returns `true` if any word in the Trie starts with the prefix `word`, and `false` otherwise.

## Queries

You will be given multiple queries of three types:

1. `(1, word)`: Calls the `insert(word)` function and inserts the word into the Trie.
2. `(2, word)`: Calls the `search(word)` function and checks whether the word exists in the Trie or not.
3. `(3, word)`: Calls the `isPrefix(word)` function and checks whether the word exists as a prefix of any string in the Trie.

## Input Format

- The first line contains an integer `t`, the number of test cases.
- For each test case:
  - An integer `q`, the number of queries.
  - Then, `q` lines follow where each line contains:
    - An integer `x` (1, 2, or 3) representing the query type.
    - A string `word` of length `n` (1 ≤ `n` ≤ 10^3) representing the word.

## Output Format

For each test case, output a single line containing the result of all `search()` and `isPrefix()` queries, separated by spaces, with the result of each query being either `true` or `false`.

### Example 1:

**Input**:
```plaintext
1
6
1 abcd
1 abc
1 bcd
2 bc
3 bc
2 abc
