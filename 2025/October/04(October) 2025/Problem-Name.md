## Expression Add Operators

**Difficulty:** Hard
**Accuracy:** 61.49%
**Submissions:** 28K+
**Points:** 8
**Average Time:** 40m

---

### 🧩 Problem Statement

Given a string `s` that contains only digits (0-9) and an integer `target`, return all possible strings by inserting the binary operator `'+'`, `'-'`, and/or `'*'` between the digits of `s` such that the resultant expression evaluates to the target value.

#### Notes:

* Operands in the returned expressions should not contain leading zeros. (e.g., `2+03` is invalid but `20+3` is valid)
* It is allowed to not insert any operators.
* Driver code will print the final list of strings in lexicographically smallest order.

---

### 🧠 Example

**Input:**
`s = "124"`, `target = 9`
**Output:**
`["1+2*4"]`
**Explanation:** 1 + 2 * 4 = 9

**Input:**
`s = "125"`, `target = 7`
**Output:**
`["1*2+5", "12-5"]`

**Input:**
`s = "12"`, `target = 12`
**Output:**
`["12"]`

**Input:**
`s = "987612"`, `target = 200`
**Output:**
`[]`

---

### ⚙️ Constraints

* 1 ≤ s.size() ≤ 9
* s consists of only digits (0-9)
* -2³¹ ≤ target ≤ 2³¹-1

---

### 💡 Approach

We use **backtracking** to explore all valid combinations of operators between digits.

#### Key points:

1. Iterate over every possible split of digits.
2. Skip numbers with leading zeros.
3. At each recursive step:

   * Choose a number.
   * Try appending '+', '-', or '*' before it.
   * Maintain running total and previous operand to handle multiplication precedence.
4. When the end of the string is reached, if evaluated value equals `target`, add expression to result.

---

### 🧾 C++ Solution

```cpp
class Solution {
public:
    vector<string> findExpr(string &s, int target) {
        vector<string> res;
        string path;
        backtrack(s, target, 0, 0, 0, path, res);
        sort(res.begin(), res.end());
        return res;
    }

private:
    void backtrack(string &s, long long target, int pos, long long eval,
                   long long prevNum, string path, vector<string> &res) {

        // If we reached end of string
        if (pos == s.size()) {
            if (eval == target)
                res.push_back(path);
            return;
        }

        for (int i = pos; i < s.size(); ++i) {
            // Prevent numbers with leading zeros
            if (i != pos && s[pos] == '0') break;

            string curStr = s.substr(pos, i - pos + 1);
            long long curNum = stoll(curStr);

            // If starting number (no operator before)
            if (pos == 0) {
                backtrack(s, target, i + 1, curNum, curNum, curStr, res);
            } else {
                // Try addition
                backtrack(s, target, i + 1, eval + curNum, curNum,
                          path + "+" + curStr, res);
                // Try subtraction
                backtrack(s, target, i + 1, eval - curNum, -curNum,
                          path + "-" + curStr, res);
                // Try multiplication
                backtrack(s, target, i + 1, eval - prevNum + prevNum * curNum,
                          prevNum * curNum, path + "*" + curStr, res);
            }
        }
    }
};
```

---

### ⏱️ Time Complexity

* **O(3ⁿ)** — Each position can branch into 3 operator choices.

### 🧮 Space Complexity

* **O(n)** — Depth of recursion (expression length).

---

### ✅ Example Walkthrough

**Input:** `s = "125"`, `target = 7`

Paths explored:

```
1*2+5 → 7
12-5 → 7
```

**Output:**

```
["1*2+5", "12-5"]
```
