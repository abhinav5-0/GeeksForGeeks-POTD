# Equilibrium Point

This repository contains a C++ solution to find the equilibrium point in an array. The equilibrium point is an index where the sum of elements before it is equal to the sum of elements after it.

## Problem Description

### Input
- An array of integers `arr[]`.

### Output
- The first equilibrium point index (0-based indexing) if it exists, otherwise `-1`.

### Example

#### Example 1:
```plaintext
Input: arr[] = [1, 2, 0, 3]
Output: 2
Explanation: The sum of left of index 2 is 1 + 2 = 3 and the sum on right of index 2 is 0 + 3 = 3.
```

#### Example 2:
```plaintext
Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.
```

#### Example 3:
```plaintext
Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and the sum on right of index 3 is -4 + 3 + 0 = -1.
```

## Constraints
- `3 <= arr.size() <= 10^6`
- `-10^9 <= arr[i] <= 10^9`

---

## Solution

### Algorithm
1. **Calculate Total Sum**: Compute the sum of all elements in the array.
2. **Iterate Through the Array**:
   - Check if the left sum equals the right sum for each index.
3. **Update Left Sum**: Add the current element to the left sum.
4. **Return Result**: Return the index if equilibrium is found, otherwise return `-1`.

### Time Complexity
- \(O(n)\): Single traversal of the array.

### Space Complexity
- \(O(1)\): No extra space is used.

---

## File Structure

```
├── equilibrium_point.cpp   # Main C++ file with the solution.
├── README.md               # Project documentation.
```

---

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/abhinav5-0/GeeksForGeeks-POTD.git
   ```
2. Compile the code:
   ```bash
   g++ -o equilibrium equilibrium_point.cpp
   ```
3. Run the executable:
   ```bash
   ./equilibrium
   ```
4. Input the number of test cases and arrays as specified in the problem.

---

## Contribution
Contributions are welcome! Feel free to open issues or submit pull requests.

---

