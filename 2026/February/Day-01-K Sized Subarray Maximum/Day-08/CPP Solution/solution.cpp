class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0)
                swap(maxEndingHere, minEndingHere);

            maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
            minEndingHere = min(arr[i], minEndingHere * arr[i]);

            ans = max(ans, maxEndingHere);
        }
        return ans;
    }
};
