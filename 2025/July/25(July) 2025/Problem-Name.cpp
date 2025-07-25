class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int totalSum = 0;
        int maxKadane = INT_MIN, currMax = 0;
        int minKadane = INT_MAX, currMin = 0;

        for (int num : arr) {
            // For max subarray (Kadane's)
            currMax = max(num, currMax + num);
            maxKadane = max(maxKadane, currMax);

            // For min subarray
            currMin = min(num, currMin + num);
            minKadane = min(minKadane, currMin);

            // Total sum
            totalSum += num;
        }

        // If all numbers are negative, maxKadane is the result
        if (maxKadane < 0) return maxKadane;

        // Otherwise, max of normal and circular
        return max(maxKadane, totalSum - minKadane);
    }
};
