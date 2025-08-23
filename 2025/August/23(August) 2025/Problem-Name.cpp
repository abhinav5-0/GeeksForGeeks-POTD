class Solution {
  public:
    // Helper function to check if allocation is possible
    bool isPossible(vector<int> &arr, int k, int mid) {
        int students = 1;
        int pages = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return false; // single book > mid not possible
            
            if (pages + arr[i] > mid) {
                students++;   // allocate to next student
                pages = arr[i];
                
                if (students > k) return false;
            } else {
                pages += arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // Not enough books for each student

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
