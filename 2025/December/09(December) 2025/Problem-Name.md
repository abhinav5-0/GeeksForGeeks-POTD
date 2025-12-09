# Array Duplicates — Solution (Markdown)

## 🧩 Problem Summary

You are given an array `arr[]` of size `n`, where each element is in the range **1 to n**. Every element appears **at most twice**. Your task is to return all the elements that appear **exactly twice**.

* Output can be in any order (driver will sort).
* Constraints allow an **O(n)** solution with **O(1)** extra space.

---

## ✅ Optimal Approach — In-Place Marking

We use the array itself as a hash structure.

### Key Idea

For each number `x`, use index `x - 1` as its marker.

* If `arr[x - 1]` is **positive**, mark it visited by making it **negative**.
* If `arr[x - 1]` is **negative**, it means we've seen `x` before → it is a **duplicate**.

Because the values are within `1..n`, this is valid and uses no extra memory.

---

## ⏱ Complexity

* **Time:** O(n)
* **Space:** O(1) extra (in-place)

---

## ✅ C++ Code

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int x = abs(arr[i]);

            // If already visited, it's a duplicate
            if (arr[x - 1] < 0) {
                ans.push_back(x);
            } else {
                arr[x - 1] = -arr[x - 1];
            }
        }

        return ans;
    }
};
```

---

## 📝 Example

### Input

```
arr = [2, 3, 1, 2, 3]
```

### Output

```
[2, 3]
```

### Walkthrough

| Step | Value x | arr[x-1] state | Action    | Duplicate? |
| ---- | ------- | -------------- | --------- | ---------- |
| 0    | 2       | +3             | mark -3   | No         |
| 1    | 3       | +1             | mark -1   | No         |
| 2    | 1       | +2             | mark -2   | No         |
| 3    | 2       | -3             | duplicate | ✔ 2        |
| 4    | 3       | -1             | duplicate | ✔ 3        |

---

## 🎯 Final Answer

The duplicates are efficiently found using in-place sign marking.
