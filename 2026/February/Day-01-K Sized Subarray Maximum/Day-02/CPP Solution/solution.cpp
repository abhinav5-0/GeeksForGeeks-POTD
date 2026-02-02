class Solution {
public:
    int kadaneMax(vector<int>& arr) {
        int curr = arr[0], best = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            best = max(best, curr);
        }
        return best;
    }

    int kadaneMin(vector<int>& arr) {
        int curr = arr[0], best = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = min(arr[i], curr + arr[i]);
            best = min(best, curr);
        }
        return best;
    }

    int maxCircularSum(vector<int>& arr) {
        int normalMax = kadaneMax(arr);
        
        // If all numbers are negative
        if (normalMax < 0) return normalMax;

        int totalSum = 0;
        for (int x : arr) totalSum += x;

        int minSubarray = kadaneMin(arr);

        return max(normalMax, totalSum - minSubarray);
    }
};
