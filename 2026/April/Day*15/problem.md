# URLify a Given String

## 🧩 Problem Statement

Given a string `s`, replace all the spaces in the string with `%20`.

---

## 📌 Examples

### Example 1

**Input:**
`s = "i love programming"`

**Output:**
`"i%20love%20programming"`

**Explanation:**
The 2 spaces are replaced by `%20`.

---

### Example 2

**Input:**
`s = "Mr Benedict Cumberbatch"`

**Output:**
`"Mr%20Benedict%20Cumberbatch"`

**Explanation:**
The 2 spaces are replaced by `%20`.

---

## ⚙️ Constraints

* `1 ≤ s.size() ≤ 10^4`

---

## 💡 Approach

* Traverse the string character by character.
* If the character is a space (`' '`), replace it with `%20`.
* Otherwise, keep the character as it is.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (for new string)

---

## 🚀 Code Implementations

### C++

```cpp
class Solution {
public:
    string URLify(string &s) {
        string result = "";
        for(char c : s) {
            if(c == ' ') result += "%20";
            else result += c;
        }
        return result;
    }
};
```

---

### Java

```java
class Solution {
    String URLify(String s) {
        StringBuilder result = new StringBuilder();
        
        for(char c : s.toCharArray()) {
            if(c == ' ') result.append("%20");
            else result.append(c);
        }
        
        return result.toString();
    }
}
```

---

### Python

```python
class Solution:
    def URLify(self, s: str) -> str:
        result = ""
        for c in s:
            if c == ' ':
                result += "%20"
            else:
                result += c
        return result
```

---

## ✅ Summary

* Replace spaces with `%20`
* Simple string traversal problem
* Very common in interviews (related to URL encoding)
