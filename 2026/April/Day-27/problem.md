# Smallest Window Containing 0, 1 and 2

## 🧩 Problem

Given a string `s` consisting only of characters **'0'**, **'1'**, and **'2'**, determine the length of the **smallest substring** that contains all three characters at least once.

If no such substring exists, return `-1`.

---

## 📌 Examples

### Example 1

```
Input: s = "10212"
Output: 3
```

**Explanation:** The substring `"102"` is the shortest substring containing `'0'`, `'1'`, and `'2'`.

---

### Example 2

```
Input: s = "12121"
Output: -1
```

**Explanation:** The character `'0'` is not present in the string.

---

## 🔒 Constraints

* `1 ≤ s.size() ≤ 10^5`

---

## 💡 Approach (Sliding Window)

We use the **two-pointer (sliding window)** technique:

1. Maintain a window `[left, right]`
2. Expand `right` to include characters
3. Track counts of `'0'`, `'1'`, `'2'`
4. When all are present:

   * Try shrinking from `left`
   * Update minimum length

---

## 🚀 C++ Solution

```cpp
class Solution {
public:
    int smallestSubstring(string s) {
        int n = s.size();
        vector<int> count(3, 0);
        int left = 0, ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            count[s[right] - '0']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans = min(ans, right - left + 1);
                count[s[left] - '0']--;
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```

---

## 🐍 Python Solution

```python
class Solution:
    def smallestSubstring(self, s: str) -> int:
        count = [0, 0, 0]
        left = 0
        ans = float('inf')

        for right in range(len(s)):
            count[int(s[right])] += 1

            while all(c > 0 for c in count):
                ans = min(ans, right - left + 1)
                count[int(s[left])] -= 1
                left += 1

        return -1 if ans == float('inf') else ans
```

---

## ☕ Java Solution

```java
class Solution {
    public int smallestSubstring(String s) {
        int[] count = new int[3];
        int left = 0;
        int ans = Integer.MAX_VALUE;

        for (int right = 0; right < s.length(); right++) {
            count[s.charAt(right) - '0']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans = Math.min(ans, right - left + 1);
                count[s.charAt(left) - '0']--;
                left++;
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
```

---

## ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

---

## ✅ Key Idea

Keep shrinking the window whenever all three characters are present to ensure the substring is as small as possible.
