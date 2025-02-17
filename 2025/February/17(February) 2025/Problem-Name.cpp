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
