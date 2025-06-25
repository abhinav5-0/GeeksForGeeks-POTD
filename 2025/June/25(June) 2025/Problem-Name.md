# Problem: Check if Frequencies Can Be Equal

**Difficulty:** Medium
**Accuracy:** 16.67%
**Submissions:** 136K+
**Points:** 4

## Problem Statement

Given a string `s` consisting only of lowercase alphabetic characters, check whether it is possible to remove at most one character such that the frequency of each distinct character in the string becomes the same. Return `true` if it is possible; otherwise, return `false`.

## Examples

### Example 1:

**Input:**

```txt
s = "xyyz"
```

**Output:**

```txt
true
```

**Explanation:**
Removing one 'y' will make the frequency of each distinct character equal to 1.

### Example 2:

**Input:**

```txt
s = "xyyzz"
```

**Output:**

```txt
true
```

**Explanation:**
Removing one 'x' will make the frequency of each distinct character equal to 2.

### Example 3:

**Input:**

```txt
s = "xxxxyyzz"
```

**Output:**

```txt
false
```

**Explanation:**
Frequencies cannot be made equal by removing at most one character.

## Constraints

* 1 <= s.size() <= 10^5

## Function Signature

```cpp
class Solution {
public:
    bool sameFreq(string& s);
};
```

## Approach

1. Count the frequency of each character.
2. Count how many times each frequency appears.
3. The string is valid if:

   * All characters already have the same frequency.
   * One character has frequency 1 and occurs only once.
   * One character has a frequency one more than the others and occurs only once.
4. Otherwise, return false.

## C++ Implementation

```cpp
class Solution {
public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        unordered_map<int, int> freqCount;

        for (char c : s)
            freq[c]++;

        for (auto& it : freq)
            freqCount[it.second]++;

        if (freqCount.size() == 1)
            return true;

        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;

            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1))
                return true;

            if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)))
                return true;
        }

        return false;
    }
};
```

## Tags

* Hashing
* Frequency Count
* String
* Greedy
