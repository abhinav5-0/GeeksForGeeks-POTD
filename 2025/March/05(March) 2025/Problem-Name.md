# Longest String Chain

## Problem Statement
You are given an array of words where each word consists of lowercase English letters.

A word `wordA` is a predecessor of `wordB` if and only if we can insert exactly one letter anywhere in `wordA` without changing the order of the other characters to make it equal to `wordB`. 

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words `[word1, word2, ..., wordk]` with `k >= 1`, where `word1` is a predecessor of `word2`, `word2` is a predecessor of `word3`, and so on. A single word is trivially a word chain with `k = 1`.

Return the length of the longest possible word chain with words chosen from the given list of words in any order.

## Example

### Input:
```cpp
words[] = {"ba", "b", "a", "bca", "bda", "bdca"};
```

### Output:
```cpp
4
```

### Explanation:
One of the longest word chains is `["a", "ba", "bda", "bdca"]`.

## Constraints:
- `1 <= words.length <= 10^4`
- `1 <= words[i].length <= 10`
- `words[i]` only consists of lowercase English letters.

---

## Solution Approach

### Algorithm:
1. **Sorting Words by Length:** Sort words in increasing order of length.
2. **Dynamic Programming with HashMap:** Maintain a hashmap `dp[word]` that stores the longest chain ending at each word.
3. **Checking Possible Predecessors:**
   - Generate potential predecessors by removing one character at a time.
   - Update `dp[word]` based on the longest chain found so far.
4. **Finding the Maximum Chain Length:** The answer is the maximum value in `dp`.

### Code Implementation:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool compare(const string &a, const string &b) {
        return a.length() < b.length();
    }
    
    bool isPredecessor(const string &a, const string &b) {
        if (a.length() + 1 != b.length()) return false;
        int i = 0, j = 0;
        bool inserted = false;
        while (j < b.length()) {
            if (i < a.length() && a[i] == b[j]) {
                i++;
            } else {
                if (inserted) return false;
                inserted = true;
            }
            j++;
        }
        return true;
    }
    
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int maxLength = 1;
        
        for (const string &word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string prevWord = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prevWord) != dp.end()) {
                    dp[word] = max(dp[word], dp[prevWord] + 1);
                }
            }
            maxLength = max(maxLength, dp[word]);
        }
        return maxLength;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~" << "\n";
    }
    return 0;
}
```

### Complexity Analysis:
- **Sorting:** `O(N log N)`
- **Dynamic Programming Traversal:** `O(N * L^2)`, where `L` is the maximum word length (10 in this problem).
- **Overall Complexity:** `O(N log N + N L^2)`

### Edge Cases Considered:
- Single-word input.
- Words of the same length.
- Completely unrelated words.
- Already sorted chains.

This solution efficiently finds the longest string chain in an optimal manner using sorting and dynamic programming.
