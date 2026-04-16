# Implement Atoi

## 🧩 Problem Statement

Given a string `s`, convert it into a **32-bit signed integer** (similar to the `atoi` function) **without using any built-in conversion functions**.

---

## ⚙️ Rules to Follow

1. **Ignore Leading Whitespaces**
   Skip all leading whitespace characters.

2. **Check Sign**

   * If the next character is `'-'` or `'+'`, take it as the sign of the number.
   * If no sign is present, assume the number is **positive**.

3. **Read Digits**

   * Read digits and ignore leading zeros.
   * Stop reading when a **non-digit character** is encountered or end of string is reached.
   * If no digits are found, return `0`.

4. **Handle Overflow**
   If the number exceeds the range of a **32-bit signed integer**:

   * Return `2^31 - 1 = 2147483647` if it exceeds maximum value.
   * Return `-2^31 = -2147483648` if it goes below minimum value.

---

## 📥 Examples

### Example 1

```
Input:  s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer.
```

### Example 2

```
Input:  s = "-"
Output: 0
Explanation: No digits are present.
```

### Example 3

```
Input:  s = "1231231231311133"
Output: 2147483647
Explanation: Value exceeds 2^31 - 1.
```

### Example 4

```
Input:  s = "-999999999999"
Output: -2147483648
Explanation: Value is less than -2^31.
```

### Example 5

```
Input:  s = "  -0012gfg4"
Output: -12
Explanation: Parsing stops at non-digit character 'g'.
```

---

## 🔒 Constraints

* `1 ≤ s.length ≤ 15`

---

## 💡 Approach

1. Traverse string and skip spaces.
2. Determine sign.
3. Traverse digits and build number.
4. Check overflow before adding next digit.
5. Return result with sign.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## 🚀 Notes

* Be careful with **overflow before multiplication**.
* Use condition:

  ```cpp
  if (result > (INT_MAX - digit) / 10)
  ```

  to detect overflow early.

---

## 📌 Tags

* Strings
* Parsing
* Simulation
