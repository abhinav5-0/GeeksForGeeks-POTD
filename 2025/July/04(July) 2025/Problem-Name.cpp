class Solution {
  public:
    int countAtMostK(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;

        for (int right = 0; right < arr.size(); right++) {
            if (freq[arr[right]] == 0) k--;  // new distinct element
            freq[arr[right]]++;

            while (k < 0) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) k++;  // removing a distinct element
                left++;
            }

            ans += right - left + 1;  // count of subarrays ending at right
        }

        return ans;
    }
};
