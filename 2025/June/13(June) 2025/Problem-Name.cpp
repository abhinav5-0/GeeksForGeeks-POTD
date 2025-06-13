class Solution {
  public:
    int calculateHours(vector<int>& arr, int s) {
        int hours = 0;
        for (int pile : arr) {
            hours += (pile + s - 1) / s; // Equivalent to ceil(pile / s)
        }
        return hours;
    }

    int kokoEat(vector<int>& arr, int k) {
        int left = 1, right = *max_element(arr.begin(), arr.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int hoursNeeded = calculateHours(arr, mid);

            if (hoursNeeded <= k) {
                answer = mid;
                right = mid - 1; // Try smaller s
            } else {
                left = mid + 1; // Need higher s
            }
        }

        return answer;
    }
};
