# Remove Spaces

## 📝 Problem Statement

Given a string `s`, remove all the spaces from the string and return the modified string.

---

## 📊 Details

* **Difficulty:** Basic
* **Accuracy:** 49.21%
* **Submissions:** 94K+
* **Points:** 1

---

## 📥 Examples

### Example 1

**Input:**
`s = "g eeks for ge eks"`

**Output:**
`"geeksforgeeks"`

**Explanation:**
All space characters are removed from the given string while preserving the order of the remaining characters.

---

### Example 2

**Input:**
`s = "abc d"`

**Output:**
`"abcd"`

**Explanation:**
All space characters are removed while maintaining the order of characters.

---

## ⚙️ Constraints

* `1 ≤ |s| ≤ 10^5`

---

## 💡 Approach

* Traverse the string.
* Skip spaces.
* Append non-space characters to the result.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## 💻 Code Implementations

### C++

```cpp
class Solution {
public:
    string removeSpaces(string& s) {
        string result = "";
        for(char c : s) {
            if(c != ' ') {
                result += c;
            }
        }
        return result;
    }
};
```

### Java

```java
class Solution {
    String removeSpaces(String s) {
        StringBuilder result = new StringBuilder();
        for(char c : s.toCharArray()) {
            if(c != ' ') {
                result.append(c);
            }
        }
        return result.toString();
    }
}
```

### Python

```python
class Solution:
    def removeSpaces(self, s: str) -> str:
        result = ""
        for c in s:
            if c != ' ':
                result += c
        return result
```

---

## 🚀 Alternative (Built-in Methods)

### C++

```cpp
#include <algorithm>
s.erase(remove(s.begin(), s.end(), ' '), s.end());
```

### Java

```java
return s.replace(" ", "");
```

### Python

```python
return s.replace(" ", "")
```

---

## ✅ Summary

* Remove spaces using iteration or built-in methods.
* Maintain character order.
* Efficient solution runs in linear time.
