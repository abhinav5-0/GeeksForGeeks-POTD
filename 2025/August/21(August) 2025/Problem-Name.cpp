class Solution {
  public:
    bool canPlace(vector<int>& arr, int k, int dist) {
        int count = 1;   // first element always chosen
        int last = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) {
                count++;
                last = arr[i];
                if (count >= k) return true;
            }
        }
        return false;
    }
    
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 0, high = arr.back() - arr.front();
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(arr, k, mid)) {
                ans = mid;     // mid is possible
                low = mid + 1; // try for bigger distance
            } else {
                high = mid - 1; // decrease distance
            }
        }
        return ans;
    }
};
