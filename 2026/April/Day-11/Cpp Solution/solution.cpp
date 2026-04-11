class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        long long count = 0;
        long long len = 1;
        int n = arr.size();

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1]) {
                len++;
            } else {
                count += (len * (len - 1)) / 2;
                len = 1;
            }
        }

        count += (len * (len - 1)) / 2;
        return count;
    }
};
