class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int count = 0;
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            if (arr[left] + arr[right] < target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        
        return count;
    }
};
