# Subarrays with Sum K

## Problem Description
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number `k`.

### Examples

#### Example 1:
```text
Input: arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explanation: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
```

#### Example 2:
```text
Input: arr = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explanation: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
```

#### Example 3:
```text
Input: arr = [1, 3, 5], k = 0
Output: 0
Explanation: No subarray with sum equal to 0.
```

### Constraints
- `1 ≤ arr.size() ≤ 10^5`
- `-10^3 ≤ arr[i] ≤ 10^3`
- `-10^7 ≤ k ≤ 10^7`

---

## Solution
The problem is solved efficiently using the **prefix sum technique** combined with a hash map.

### Approach
1. Use a running sum (`currentSum`) to calculate the prefix sum as we iterate through the array.
2. Maintain a hash map to store the frequency of prefix sums encountered.
3. For each element in the array:
   - Check if the difference `currentSum - k` exists in the hash map.
   - If it does, add its frequency to the count of subarrays.
   - Update the hash map with the current prefix sum.

### Algorithm
```cpp
class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;

        // Initialize hash map with 0 sum having frequency 1.
        prefixSumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;

            // Check if there's a prefix sum that matches currentSum - k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Update the frequency of the current sum in the hash map
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
```

---

## Usage
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```

2. Compile and run the program:
   ```bash
   g++ -o main main.cpp -std=c++17
   ./main
   ```

3. Input the test cases as required.

---

## Example Input/Output

### Input:
```
1
-10
10 2 -2 -20 10
```

### Output:
```
3
~
```

---

## Complexity Analysis

- **Time Complexity**: `O(n)`
  - Each element in the array is processed once, and hash map operations (insert/find) are \(O(1)\) on average.

- **Space Complexity**: `O(n)`
  - The hash map can store up to \(n\) unique prefix sums in the worst case.

---

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any bugs or feature enhancements.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
