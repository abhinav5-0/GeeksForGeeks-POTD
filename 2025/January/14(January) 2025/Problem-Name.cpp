class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0); 
        int leftSum = 0; 
        for (int i = 0; i < arr.size(); i++) {
            if (leftSum == totalSum - leftSum - arr[i]) {
                return i;
            }
            leftSum += arr[i]; 
        }
        return -1; 
    }
};
