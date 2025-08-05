### Problem: Palindrome Sentence

**Difficulty:** Easy  
**Accuracy:** 50.04%  
**Submissions:** 38K+  
**Points:** 2

---

### Problem Statement:

Given a single string `s`, check if it is a **palindrome sentence** or not.

A **palindrome sentence** is a sequence of characters, such as a word, phrase, or series of symbols that reads the same backward as forward **after**:
- Converting all uppercase letters to lowercase.
- Removing all **non-alphanumeric** characters (including spaces and punctuation).

---

### Examples:

**Input:** `"Too hot to hoot"`  
**Output:** `true`  
**Explanation:** Becomes `"toohottohoot"`, which is a palindrome.

**Input:** `"Abc 012..## 10cbA"`  
**Output:** `true`  
**Explanation:** Becomes `"abc01210cba"`, which is a palindrome.

**Input:** `"ABC $. def01ASDF"`  
**Output:** `false`  
**Explanation:** Becomes `"abcdef01asdf"`, which is not a palindrome.

---

### Constraints:
- 1 ≤ s.length() ≤ 10^6

---

### C++ Solution

```cpp
class Solution {
  public:
    bool isPalinSent(string &s) {
        string cleaned;
        
        // Remove non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        // Check if cleaned string is a palindrome
        int left = 0, right = cleaned.size() - 1;
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
```

---

### Time Complexity:
- O(n) — where n is the length of the input string `s`

### Space Complexity:
- O(n) — for storing the cleaned version of the string
