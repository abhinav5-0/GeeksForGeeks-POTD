# Count Distinct Elements in Every Window

## Problem Statement

Given an integer array `arr[]` and a number `k`, find the count of distinct elements in every window of size `k` in the array.

### Examples

#### Example 1:
Input:
```text
arr[] = [1, 2, 1, 3, 4, 2, 3]
k = 4
```
Output:
```text
[3, 4, 4, 3]
```
Explanation:
- Window 1: {1, 2, 1, 3} → 3 distinct elements.
- Window 2: {2, 1, 3, 4} → 4 distinct elements.
- Window 3: {1, 3, 4, 2} → 4 distinct elements.
- Window 4: {3, 4, 2, 3} → 3 distinct elements.

#### Example 2:
Input:
```text
arr[] = [4, 1, 1]
k = 2
```
Output:
```text
[2, 1]
```
Explanation:
- Window 1: {4, 1} → 2 distinct elements.
- Window 2: {1, 1} → 1 distinct element.

#### Constraints:
- \(1 \leq k \leq \text{arr.size()} \leq 10^5\)
- \(1 \leq \text{arr[i]} \leq 10^5\)

---

## Solution

The problem is solved using a sliding window technique combined with hashing to efficiently count distinct elements in each window.

### Approach:
1. **Use a Hash Map**:
   - Store the frequency of elements in the current window.
2. **Sliding Window**:
   - For each new element entering the window, increase its count in the hash map.
   - For the element leaving the window, decrease its count and remove it if its frequency becomes zero.
3. **Output the Result**:
   - The size of the hash map at each step gives the number of distinct elements.

### Complexity:
- **Time Complexity**: \(O(n)\) because each element is added and removed from the hash map at most once.
- **Space Complexity**: \(O(k)\) due to the hash map storing up to \(k\) distinct elements.

---

## Usage

### Compilation and Execution
1. Compile the code:
   ```bash
   g++ -std=c++17 -o count_distinct count_distinct.cpp
   ```
2. Run the program:
   ```bash
   ./count_distinct
   ```

### Input Format
1. The first line contains an integer `t`, the number of test cases.
2. For each test case:
   - First line contains two integers `n` (size of the array) and `k` (window size).
   - Second line contains `n` integers representing the array elements.

### Output Format
- For each test case, output a single line containing the distinct count for each window separated by spaces.

---

## Example Input/Output

### Input:
```text
1
7 4
1 2 1 3 4 2 3
```

### Output:
```text
3 4 4 3
```

---

## Files

- `count_distinct.cpp`: Contains the main implementation of the solution.
- `README.md`: Documentation for the project.

---


