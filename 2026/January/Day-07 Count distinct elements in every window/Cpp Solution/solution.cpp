class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            // add current element
            freq[arr[i]]++;

            // remove element going out of window
            if (i >= k) {
                freq[arr[i - k]]--;
                if (freq[arr[i - k]] == 0)
                    freq.erase(arr[i - k]);
            }

            // store result when window size becomes k
            if (i >= k - 1)
                ans.push_back(freq.size());
        }
        return ans;
    }
};
