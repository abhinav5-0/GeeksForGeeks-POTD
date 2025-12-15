## Count Indices to Balance Even and Odd Sums

**Difficulty:** Medium
**Accuracy:** 74.07%
**Points:** 4

---

### 🔍 Problem Statement

Given an array `arr[]`, count the number of indices such that **deleting the element at that index** and shifting all elements after it one position left results in an array where:

* Sum of elements at **even indices** = Sum of elements at **odd indices**

---

### 📌 Examples

**Example 1**

```
Input:  arr = [2, 1, 6, 4]
Output: 1
```

Explanation:
Removing index `1` → `[2, 6, 4]`

* Even index sum = 2 + 4 = 6
* Odd index sum = 6

---

**Example 2**

```
Input:  arr = [1, 1, 1]
Output: 3
```

Explanation:
Removing any element results in equal even and odd sums.

---

### 💡 Key Insight

When an element at index `i` is removed:

* All elements **after index `i` shift left**
* Their **index parity flips** (even ↔ odd)

So we track:

* Prefix sums (left side)
* Suffix sums (right side)

After removal:

```
New Even Sum = leftEven + rightOdd
New Odd Sum  = leftOdd  + rightEven
```

If both are equal → valid index.

---

### ⚙️ Algorithm (O(n) Time, O(1) Space)

1. Calculate total sums of even and odd indexed elements
2. Traverse the array index by index
3. Temporarily remove the current element
4. Compare new even and odd sums
5. Restore prefix sums and continue

---

### 💻 C++ Implementation

```cpp
class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        
        int totalEven = 0, totalOdd = 0;
        
        // Calculate total sums
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }
        
        int leftEven = 0, leftOdd = 0;
        int rightEven = totalEven, rightOdd = totalOdd;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            // Remove current element from right
            if (i % 2 == 0) rightEven -= arr[i];
            else rightOdd -= arr[i];
            
            // Check balance condition
            if (leftEven + rightOdd == leftOdd + rightEven)
                count++;
            
            // Add current element to left
            if (i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }
        
        return count;
    }
};
```

---

### ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

### ✅ Final Notes

* Efficient for large inputs up to `10^5`
* No extra arrays required
* Common interview pattern involving prefix & suffix sums

---

⭐ *Great problem to master index-parity based prefix sum techniques!*
