# Anagram Palindrome

## 🧩 Problem Statement

Given a string `s`, determine whether its characters can be rearranged to form a palindrome.

Return **true** if it is possible to rearrange the string into a palindrome; otherwise, return **false**.

---

## 💡 Examples

### Example 1

```
Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba"
```

### Example 2

```
Input: s = "geeksogeeks"
Output: true
Explanation: The characters can be rearranged to form "geeksoskeeg"
```

### Example 3

```
Input: s = "geeksforgeeks"
Output: false
Explanation: The string cannot be rearranged into a palindrome
```

---

## 🔒 Constraints

* `1 ≤ s.length ≤ 10^6`
* `s` consists of only lowercase English letters

---

## 🧠 Approach

To form a palindrome:

* Each character must appear an **even number of times**
* At most **one character** can have an **odd frequency** (middle character in odd-length palindrome)

### Steps:

1. Count frequency of each character
2. Count how many characters have odd frequency
3. If odd count > 1 → return false
4. Else → return true

---

## ⚡ C++ Solution

```cpp
class Solution {
public:
    bool canFormPalindrome(string &s) {
        vector<int> freq(26, 0);
        
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        for(int f : freq) {
            if(f % 2 != 0) oddCount++;
        }
        
        return oddCount <= 1;
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    boolean canFormPalindrome(String s) {
        int[] freq = new int[26];
        
        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        for(int f : freq) {
            if(f % 2 != 0) oddCount++;
        }
        
        return oddCount <= 1;
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def canFormPalindrome(self, s: str) -> bool:
        freq = [0] * 26
        
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        odd_count = sum(1 for f in freq if f % 2 != 0)
        
        return odd_count <= 1
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1) (since only 26 characters)

---

## ✅ Key Insight

A string can form a palindrome **iff** at most **one character has an odd frequency**.
