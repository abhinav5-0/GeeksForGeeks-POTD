class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int maxArea = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int area = height * width;
            maxArea = max(maxArea, area);

            // Move the pointer with smaller height
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
