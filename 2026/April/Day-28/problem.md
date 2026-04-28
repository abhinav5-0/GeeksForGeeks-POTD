# Longest Repeating Character Replacement

## 🧩 Problem Statement

Given a string `s` of length `n` consisting of uppercase English letters and an integer `k`, you are allowed to perform **at most `k` operations**.

In each operation, you can change any character of the string to any other uppercase English letter.

Your task is to determine the **length of the longest substring** that can be transformed into a string with all identical characters after performing at most `k` operations.

---

## 📌 Examples

### Example 1

```
Input: s = "ABBA", k = 2
Output: 4
```

**Explanation:**
We can replace both 'A' with 'B' → "BBBB". So the answer is 4.

### Example 2

```
Input: s = "ADBD", k = 1
Output: 3
```

**Explanation:**
Replace 'B' with 'D' → "ADDD". The substring "DDD" has length 3.

---

## 🔒 Constraints

* `1 ≤ n, k ≤ 10^5`
* `s` consists of only uppercase English letters

---

## 💡 Approach (Sliding Window)

We use a **sliding window** technique:

* Maintain a window `[left, right]`
* Track frequency of characters in the window
* Keep track of `maxFreq` → the frequency of the most common character in the window

### Key Idea:

To make all characters in the window same:

```
window_size - maxFreq <= k
```

If this condition fails, shrink the window from the left.

---

## 🚀 C++ Solution

```cpp
class Solution {
public:
    int longestSubstr(string& s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, result = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If more than k replacements needed, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    public int longestSubstr(String s, int k) {
        int[] freq = new int[26];
        int left = 0, maxFreq = 0, result = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s.charAt(right) - 'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(right) - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s.charAt(left) - 'A']--;
                left++;
            }

            result = Math.max(result, right - left + 1);
        }

        return result;
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def longestSubstr(self, s: str, k: int) -> int:
        freq = [0] * 26
        left = 0
        maxFreq = 0
        result = 0

        for right in range(len(s)):
            freq[ord(s[right]) - ord('A')] += 1
            maxFreq = max(maxFreq, freq[ord(s[right]) - ord('A')])

            while (right - left + 1) - maxFreq > k:
                freq[ord(s[left]) - ord('A')] -= 1
                left += 1

            result = max(result, right - left + 1)

        return result
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(26)` → constant space

---

## 🧠 Key Takeaways

* Sliding window is optimal for substring problems
* Track most frequent character to minimize replacements
* Condition `(window size - maxFreq)` is crucial

---

✅ This is a classic **LeetCode Medium** problem and frequently asked in interviews.
