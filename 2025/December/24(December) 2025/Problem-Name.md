# Count Elements Less Than or Equal to x in a Sorted Rotated Array

## 🧩 Problem Statement

Given a **sorted array that has been rotated at an unknown pivot**, containing **distinct positive integers**, and a value `x`, count how many elements in the array are **less than or equal to `x`**.

---

## 🔍 Examples

### Example 1

**Input:**

```
arr = [4, 5, 8, 1, 3], x = 6
```

**Output:**

```
4
```

**Explanation:**
Elements less than or equal to `6` are: `1, 3, 4, 5`

---

### Example 2

**Input:**

```
arr = [6, 10, 12, 15, 2, 4, 5], x = 14
```

**Output:**

```
6
```

**Explanation:**
All elements except `15` are less than or equal to `14`.

---

## 💡 Approach

Since the array is **sorted but rotated**, we cannot directly apply binary search on the whole array. Instead:

1. **Find the pivot index** (index of the minimum element) using binary search.
2. This divides the array into **two sorted subarrays**:

   * From `pivot` to `n-1`
   * From `0` to `pivot-1`
3. Apply binary search on both subarrays to count elements `≤ x`.
4. Add both counts.

---

## ⚙️ Algorithm

### Step 1: Find Pivot (Minimum Element Index)

* Use binary search
* If `arr[mid] > arr[high]`, pivot is on the right
* Otherwise, pivot is on the left or at `mid`

### Step 2: Count Elements ≤ x in a Sorted Range

* Perform binary search to find the **rightmost element ≤ x**

---

## 🧪 C++ Implementation

```cpp
class Solution {
public:
    // Find index of minimum element
    int findPivot(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = findPivot(arr);

        // If x is smaller than smallest element
        if (x < arr[pivot]) return 0;

        // If x is greater than or equal to largest element
        if (x >= arr[pivot == 0 ? n - 1 : pivot - 1])
            return n;

        int count = 0;

        // Count in right sorted part
        if (x >= arr[pivot]) {
            count += upper_bound(arr.begin() + pivot, arr.end(), x)
                     - (arr.begin() + pivot);
        }

        // Count in left sorted part
        count += upper_bound(arr.begin(), arr.begin() + pivot, x)
                 - arr.begin();

        return count;
    }
};


```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

---

## ✅ Key Takeaways

* Rotated sorted arrays can still be solved efficiently using binary search
* Finding the pivot simplifies many rotated-array problems
* Works well within large constraints (`n ≤ 10^5`)

---

🎯 *This approach is optimal and interview-friendly.*
