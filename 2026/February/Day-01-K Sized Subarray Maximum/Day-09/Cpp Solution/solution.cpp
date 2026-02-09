class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int minIndex = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }
};
