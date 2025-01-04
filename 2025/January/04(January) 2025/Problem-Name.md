# Problem of the Day: Count Triplets

## Problem Statement

Given an array of integers `arr[]` and an integer `target`, count the number of unique triplets `(i, j, k)` such that:

1. \( i < j < k \),
2. \( arr[i] + arr[j] + arr[k] = \text{target} \).

## Function Signature
```cpp
int countTriplets(vector<int>& arr, int target);
Input:
An array arr[] of integers.
A target integer target.
Output:
An integer representing the number of valid triplets in the array.
Example
Example 1:
Input:

cpp
Copy code
arr = [1, 2, 2, 3, 3, 3]
target = 8
Output:

cpp
Copy code
2
Explanation: There are two triplets that sum to the target (8): (2, 3, 3) and (2, 3, 3).

Example 2:
Input:

cpp
Copy code
arr = [1, 1, 1]
target = 3
Output:

cpp
Copy code
1
Explanation: There is only one valid triplet: (1, 1, 1).

Solution
Approach
We will iterate through the array with the first element of the triplet fixed (arr[i]).
Using a two-pointer technique, we will explore all possible pairs (arr[left], arr[right]) where left starts just after i and right starts at the end of the array.
For each pair, we calculate the sum of the triplet:
If the sum is less than the target, move the left pointer to the right to increase the sum.
If the sum is greater than the target, move the right pointer to the left to decrease the sum.
If the sum matches the target, count the valid triplets.
Special handling is required when arr[left] == arr[right] to avoid overcounting identical values.
Code:
cpp
Copy code
class Solution {
public:
    int countTriplets(vector<int>& arr, int target) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    if (arr[left] == arr[right]) {
                        int count = right - left + 1;
                        res += (count * (count - 1)) / 2;
                        break;
                    } else {
                        int cnt1 = 1, cnt2 = 1;
                        while (left + 1 < right && arr[left] == arr[left + 1]) ++left, ++cnt1;
                        while (right - 1 > left && arr[right] == arr[right - 1]) --right, ++cnt2;
                        res += cnt1 * cnt2;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
Time Complexity
Time Complexity: 
𝑂
(
𝑛
2
)
O(n 
2
 ), where n is the size of the array. We iterate through the array, and for each element, we perform a two-pointer traversal, which takes linear time.
Space Complexity: 
𝑂
(
1
)
O(1), as we are only using a few variables for counting.
Conclusion
This problem can be efficiently solved using the two-pointer technique, which reduces the complexity from a brute-force 
𝑂
(
𝑛
3
)
O(n 
3
 ) approach to 
𝑂
(
𝑛
2
)
O(n 
2
 ). This makes it feasible to solve for larger input sizes.
