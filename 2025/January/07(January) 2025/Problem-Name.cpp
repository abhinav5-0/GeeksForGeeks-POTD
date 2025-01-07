class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                // Count pairs with the same value
                if (arr[left] == arr[right]) {
                    int n = right - left + 1;
                    count += (n * (n - 1)) / 2;
                    break;
                } else {
                    int countLeft = 1, countRight = 1;

                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        left++;
                        countLeft++;
                    }

                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        right--;
                        countRight++;
                    }

                    count += countLeft * countRight;
                    left++;
                    right--;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
};
