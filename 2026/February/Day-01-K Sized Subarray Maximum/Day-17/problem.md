# Maximum Number of Overlapping Intervals

## 📝 Problem Statement

You are given an array of intervals `arr[][]`, where each interval is represented by two integers `[start, end]` (inclusive).

Your task is to return the **maximum number of intervals that overlap at any point in time**.

---

## 📌 Examples

### Example 1

**Input:**
`arr[][] = [[1, 2], [2, 4], [3, 6]]`

**Output:**
`2`

**Explanation:**
The maximum overlapping intervals are 2:

* Between (1, 2) and (2, 4)
* Between (2, 4) and (3, 6)

---

### Example 2

**Input:**
`arr[][] = [[1, 8], [2, 5], [5, 6], [3, 7]]`

**Output:**
`4`

**Explanation:**
All four intervals overlap at some point between 5 and 6.

---

## 🔒 Constraints

* `2 ≤ arr.size() ≤ 2 * 10^4`
* `1 ≤ arr[i][0] < arr[i][1] ≤ 4 * 10^6`

---

## 💡 Approach (Sweep Line Algorithm)

### Step 1: Separate Start and End Times

* Create two arrays:

  * `start[]`
  * `end[]`

### Step 2: Sort Both Arrays

* Sort the start times.
* Sort the end times.

### Step 3: Use Two Pointers

* Traverse both arrays.
* If `start[i] <= end[j]`, increase current overlap.
* Otherwise, decrease overlap.

### Step 4: Track Maximum Overlap

* Maintain a variable `maxOverlap`.
* Update it during traversal.

---

## ⏱ Time Complexity

* Sorting: **O(N log N)**
* Traversal: **O(N)**
* Overall: **O(N log N)**

## 💾 Space Complexity

* **O(N)** for start and end arrays.

---

## 🧠 Key Idea

This problem is similar to finding the maximum number of people present at a party at the same time.
We count how many intervals are active at each time point and return the maximum count.
