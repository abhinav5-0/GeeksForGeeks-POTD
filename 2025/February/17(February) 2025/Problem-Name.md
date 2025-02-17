# K Largest Elements

## Description
This repository contains an implementation of an efficient algorithm to find the `k` largest elements in an array and return them in decreasing order. The solution is implemented in C++ using a **min-heap (priority queue)** approach, ensuring optimal time complexity.

## Approach
- **Min-Heap Usage**: Maintain a min-heap of size `k` to track the largest `k` elements.
- **Insertion Complexity**: Each insertion into the min-heap takes **O(log k)**.
- **Final Extraction**: Extract elements and reverse them to get the required decreasing order.
- **Overall Complexity**: **O(N log K)**, making it efficient for large inputs.

## Code Implementation
```cpp
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Min-heap to store k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Insert elements into the min-heap
        for (int num : arr) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove the smallest element
            }
        }
        
        // Extract elements from the min-heap and store them in a vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        // Reverse the result to get decreasing order
        reverse(result.begin(), result.end());
        return result;
    }
};
```


## Constraints
- `1 ≤ k ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`



