class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> groupedAnagrams;

        // Group strings by their sorted version
        for (const string& str : arr) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            groupedAnagrams[sortedStr].push_back(str);
        }

        // Collect the groups into a result vector
        vector<vector<string>> result;
        for (const string& str : arr) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            if (!groupedAnagrams[sortedStr].empty()) {
                result.push_back(groupedAnagrams[sortedStr]);
                groupedAnagrams[sortedStr].clear(); // Avoid duplication in result
            }
        }

        return result;
    }
};
