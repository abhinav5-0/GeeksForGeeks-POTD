# Maximize Partitions in a String

## Problem Statement
Given a string `s` of lowercase English alphabets, your task is to return the maximum number of substrings formed after possible partitions (probably zero) of `s` such that no two substrings have a common character.

### Examples
#### Example 1:
**Input:**  
```plaintext
s = "acbbcc"
```
**Output:**  
```plaintext
2
```
**Explanation:**  
"a" and "cbbcc" are two substrings that do not share any characters between them.

#### Example 2:
**Input:**  
```plaintext
s = "ababcbacadefegdehijhklij"
```
**Output:**  
```plaintext
3
```
**Explanation:**  
Partitioning at the index 8 and at 15 produces three substrings: “ababcbaca”, “defegde”, and “hijhklij” such that none of them have a common character.

#### Example 3:
**Input:**  
```plaintext
s = "aaa"
```
**Output:**  
```plaintext
1
```
**Explanation:**  
Since the string consists of the same characters, no further partition can be performed. Hence, the number of substrings (here the whole string is considered as the substring) is 1.

### Constraints:
- `1 ≤ s.size() ≤ 10^5`
- `'a' ≤ s[i] ≤ 'z'`

---

## Approach

1. **Find the last occurrence of each character:** First, store the last index of every character in the string.
2. **Partition the string greedily:** Iterate through the string while maintaining the rightmost boundary of the current partition.
3. **Track partitions:** If the current index matches the rightmost boundary, we count it as a partition.

### Time Complexity:
- **O(N)**, since we traverse the string twice (once to get last indices and once to find partitions).

---

## Solution (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();

        // Step 1: Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        int maxPartitions = 0;
        int currentEnd = 0, prevPartition = -1;

        // Step 2: Iterate to form partitions
        for (int i = 0; i < n; i++) {
            currentEnd = max(currentEnd, lastIndex[s[i]]);
            
            if (i == currentEnd) {  // When we reach the boundary of a partition
                maxPartitions++;
                prevPartition = i;
            }
        }

        return maxPartitions;
    }
};

// Driver Code
int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}
```

---

## Explanation with Example

#### **Example 1**
**Input:**  
```plaintext
s = "ababcbacadefegdehijhklij"
```
**Processing:**
- `a` last occurs at index 8, `b` at 5, `c` at 7, etc.
- First partition: `"ababcbaca"` (index `0-8`).
- Second partition: `"defegde"` (index `9-15`).
- Third partition: `"hijhklij"` (index `16-23`).

**Output:**  
```plaintext
3
```

#### **Example 2**
**Input:**  
```plaintext
s = "aaa"
```
**Processing:**
- Since all characters are the same, we can't partition.

**Output:**  
```plaintext
1
```

---

## Complexity Analysis
- **Building last index map:** `O(N)`
- **Iterating through string:** `O(N)`
- **Overall Complexity:** `O(N)`

This ensures optimal performance for large inputs (`s.size() ≤ 10^5`). 🚀

