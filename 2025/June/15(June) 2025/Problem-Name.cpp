class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = 0;

            for (int num : arr) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= k) {
                answer = mid;     // try to minimize the divisor
                right = mid - 1;
            } else {
                left = mid + 1;   // need bigger divisor
            }
        }
        return answer;
    }
};
