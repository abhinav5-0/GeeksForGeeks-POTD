class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        if (arr.size() % k != 0) return false;

        map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;

            if (count > 0) {
                // Try to build groups starting from 'start'
                for (int i = 0; i < k; ++i) {
                    int num = start + i;
                    if (freq[num] < count) {
                        return false; // Not enough to form a group
                    }
                    freq[num] -= count; // Use them in this group
                }
            }
        }

        return true;
    }
};
