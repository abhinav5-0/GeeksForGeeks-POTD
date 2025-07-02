class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> count;
        int start = 0, maxLen = 0;
        
        for (int end = 0; end < arr.size(); ++end) {
            count[arr[end]]++;

            while (count.size() > 2) {
                count[arr[start]]--;
                if (count[arr[start]] == 0) {
                    count.erase(arr[start]);
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
