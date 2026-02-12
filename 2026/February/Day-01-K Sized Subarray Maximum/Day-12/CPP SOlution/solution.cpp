class Solution {
public:
    bool canAchieve(vector<int>& arr, int k, int w, long long target) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0);
        
        long long waterUsed = 0;
        long long currAdd = 0;

        for (int i = 0; i < n; i++) {
            currAdd += diff[i];
            
            long long currentHeight = arr[i] + currAdd;

            if (currentHeight < target) {
                long long need = target - currentHeight;
                waterUsed += need;
                
                if (waterUsed > k) return false;

                currAdd += need;
                if (i + w < n)
                    diff[i + w] -= need;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long ans = low;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
