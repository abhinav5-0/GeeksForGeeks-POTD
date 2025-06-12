class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;

        for (int val : arr) {
            if (val == x) continue; // Exclude x if it exists

            int diff = abs(val - x);
            // Use maxHeap: pair<difference, -value> to prioritize larger value if diff is same
            maxHeap.push({diff, -val});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(-maxHeap.top().second); // get original value
            maxHeap.pop();
        }

        // Since heap gives reverse closeness order, we reverse the result
        reverse(result.begin(), result.end());

        return result;
    }
};
