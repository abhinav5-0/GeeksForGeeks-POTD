# Substrings with Exactly K Distinct Characters

## 🧩 Problem Statement

You are given a string `s` consisting of **lowercase English letters** and an integer `k`.

Your task is to **count all possible substrings** of `s` that contain **exactly `k` distinct characters**.

> 🔹 A substring is a **continuous part** of the string.

---

## 🔍 Examples

### Example 1

**Input:**

```
s = "abc", k = 2
```

**Output:**

```
2
```

**Explanation:**
Valid substrings are:

* `"ab"`
* `"bc"`

---

### Example 2

**Input:**

```
s = "aba", k = 2
```

**Output:**

```
3
```

**Explanation:**
Valid substrings are:

* `"ab"`
* `"ba"`
* `"aba"`

---

### Example 3

**Input:**

```
s = "aa", k = 1
```

**Output:**

```
3
```

**Explanation:**
Valid substrings are:

* `"a"`
* `"a"`
* `"aa"`

---

## 🧠 Key Idea (Logic Building)

Counting substrings with **exactly `k` distinct characters** directly is hard.

So we use a **smart trick**:

> ### Exactly K = At Most K − At Most (K − 1)

If we can count:

* substrings with **at most `k`** distinct characters
* substrings with **at most `k-1`** distinct characters

Then:

```
Answer = atMost(k) − atMost(k-1)
```

---

## 🚀 Sliding Window Approach

We use:

* Two pointers (`left`, `right`)
* A frequency array/map to track characters

### How it works:

1. Expand the window using `right`
2. Count distinct characters
3. If distinct > k → shrink window from `left`
4. Add `(right - left + 1)` to result

This gives **O(n)** time complexity.

---

## 🧪 Dry Run (Quick Intuition)

For `s = "aba"`, `k = 2`

* atMost(2) = 6
* atMost(1) = 3

```
Exactly 2 = 6 - 3 = 3
```

---

## ⏱ Complexity Analysis

| Metric           | Value                |
| ---------------- | -------------------- |
| Time Complexity  | **O(n)**             |
| Space Complexity | **O(26)** (constant) |

---

## ✅ Why This Approach is Best

* Works for large input size (`10^6`)
* Simple logic once sliding window is understood
* Frequently used pattern in substring problems

---

## 💡 Tip for Beginners

If sliding window feels confusing:

* First learn **"at most K"** problems
* Then apply the **subtraction trick**

Once you get this, many problems become easy 👍

---

⭐ If this explanation helped you, don’t forget to **upvote** and **bookmark**!
