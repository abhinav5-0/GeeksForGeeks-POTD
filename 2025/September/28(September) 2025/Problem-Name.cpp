class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> maxDeque, minDeque;
        int left = 0, bestLen = 0, start = 0;

        for (int right = 0; right < arr.size(); right++) {
            // maintain maxDeque (decreasing)
            while (!maxDeque.empty() && arr[maxDeque.back()] < arr[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            // maintain minDeque (increasing)
            while (!minDeque.empty() && arr[minDeque.back()] > arr[right])
                minDeque.pop_back();
            minDeque.push_back(right);

            // shrink window if condition is violated
            while (!maxDeque.empty() && !minDeque.empty() &&
                   arr[maxDeque.front()] - arr[minDeque.front()] > x) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                left++;
            }

            // update best result
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                start = left;
            }
        }

        return vector<int>(arr.begi
