class Solution {
public:
    // Find index of minimum element
    int findPivot(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = findPivot(arr);

        // If x is smaller than smallest element
        if (x < arr[pivot]) return 0;

        // If x is greater than or equal to largest element
        if (x >= arr[pivot == 0 ? n - 1 : pivot - 1])
            return n;

        int count = 0;

        // Count in right sorted part
        if (x >= arr[pivot]) {
            count += upper_bound(arr.begin() + pivot, arr.end(), x)
                     - (arr.begin() + pivot);
        }

        // Count in left sorted part
        count += upper_bound(arr.begin(), arr.begin() + pivot, x)
                 - arr.begin();

        return count;
    }
};
