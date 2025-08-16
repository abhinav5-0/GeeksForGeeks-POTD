class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Convert numbers to strings
        vector<string> nums;
        for (int num : arr) {
            nums.push_back(to_string(num));
        }

        // Custom comparator
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If the largest number is "0", return "0"
        if (nums[0] == "0") return "0";

        // Concatenate result
        string result = "";
        for (string &s : nums) {
            result += s;
        }

        return result;
    }
};
