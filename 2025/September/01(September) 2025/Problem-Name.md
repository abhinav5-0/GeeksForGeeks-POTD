# Sum of Mode

## Problem Statement
Given an array `arr[]` of positive integers and an integer `k`, find the **sum of the modes** of all the subarrays of size `k`.

- The **mode** of a subarray is the element that occurs with the highest frequency.
- If multiple elements have the same highest frequency, the smallest such element is considered the mode.

### Examples

**Input:**
```
arr = [1, 2, 3, 2, 5, 2, 4, 4], k = 3
```
**Output:**
```
13
```
Explanation: The modes of subarrays of size 3 are `[1, 2, 2, 2, 2, 4]`, sum = 13.

**Input:**
```
arr = [1, 2, 1, 3, 5], k = 2
```
**Output:**
```
6
```
Explanation: The modes of subarrays of size 2 are `[1, 1, 1, 3]`, sum = 6.

---

## Constraints
- `1 ≤ k ≤ arr.size() ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^5`

---

## Approach
1. Use a **sliding window** of size `k`.
2. Maintain:
   - `freq` (unordered_map): element → frequency.
   - `freqToElements` (map<int, set<int>>): frequency → elements with that frequency.
   - `maxFreq`: maximum frequency in the current window.
3. For each window:
   - Insert the new element, update frequencies.
   - Remove the outgoing element, update frequencies.
   - Mode = smallest element in `freqToElements[maxFreq]`.
   - Add it to the running sum.

This ensures **O(n log n)** time complexity.

---

## C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;  // element -> frequency
        map<int, set<int>> freqToElements; // freq -> elements with that freq
        int sum = 0, maxFreq = 0;

        auto add = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = oldFreq + 1;
            freq[x] = newFreq;

            if (oldFreq > 0) {
                freqToElements[oldFreq].erase(x);
                if (freqToElements[oldFreq].empty())
                    freqToElements.erase(oldFreq);
            }
            freqToElements[newFreq].insert(x);
            maxFreq = max(maxFreq, newFreq);
        };

        auto remove = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = oldFreq - 1;
            freq[x] = newFreq;

            freqToElements[oldFreq].erase(x);
            if (freqToElements[oldFreq].empty())
                freqToElements.erase(oldFreq);

            if (newFreq > 0) {
                freqToElements[newFreq].insert(x);
            }

            if (freqToElements.find(maxFreq) == freqToElements.end())
                maxFreq--;
        };

        // First window
        for (int i = 0; i < k; i++) {
            add(arr[i]);
        }
        sum += *freqToElements[maxFreq].begin();

        // Slide window
        for (int i = k; i < n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            sum += *freqToElements[maxFreq].begin();
        }

        return sum;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** O(n log n) (due to map & set operations per insertion/removal)
- **Space Complexity:** O(n) (for storing frequencies)

---

✅ Efficient for `n ≤ 10^5`. 
