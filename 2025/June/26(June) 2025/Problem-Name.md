## Game with String

**Difficulty:** Medium  
**Accuracy:** 53.96%  
**Submissions:** 66K+  
**Points:** 4  
**Average Time:** 15m

### Problem Statement

Given a string `s` consisting of lowercase alphabets and an integer `k`, your task is to find the **minimum possible value** of the string after **removing exactly `k` characters**.

The **value of the string** is defined as the **sum of the squares of the frequencies** of each distinct character present in the string.

---

### Examples

#### Example 1:
**Input:**
```
s = "abbccc"
k = 2
```
**Output:**
```
6
```
**Explanation:**
- Remove two 'c's: Frequencies become `a:1, b:2, c:1`
- Value = `1^2 + 2^2 + 1^2 = 1 + 4 + 1 = 6`

#### Example 2:
**Input:**
```
s = "aaab"
k = 2
```
**Output:**
```
2
```
**Explanation:**
- Remove two 'a's: Frequencies become `a:1, b:1`
- Value = `1^2 + 1^2 = 2`

---

### Constraints
- `0 ≤ k ≤ s.length() ≤ 10^5`

---

### C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<int> maxHeap;
        for (auto &entry : freq) {
            maxHeap.push(entry.second);
        }

        while (k-- && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            if (top > 1)
                maxHeap.push(top - 1);
        }

        int result = 0;
        while (!maxHeap.empty()) {
            int val = maxHeap.top();
            maxHeap.pop();
            result += val * val;
        }

        return result;
    }
};
```

---

### Approach
- Count the frequency of each character.
- Use a max-heap to always remove from the character with the highest frequency.
- After `k` removals, calculate the sum of the squares of the remaining frequencies.

---

### Tags
- Greedy
- Priority Queue
- String Manipulation
- Heap
