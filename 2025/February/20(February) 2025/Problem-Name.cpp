class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        priority_queue<int> maxHeap; // Max heap for the smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the larger half

        for (int num : arr) {
            // Step 1: Insert into one of the heaps
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Step 2: Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Step 3: Calculate median
            if (maxHeap.size() == minHeap.size()) {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                result.push_back(maxHeap.top());
            }
        }
        return result;
    }
};
