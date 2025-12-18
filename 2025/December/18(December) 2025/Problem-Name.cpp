class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> odd, even;

        // Separate odd and even numbers
        for (int x : arr) {
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        // Sort odds in descending order
        sort(odd.begin(), odd.end(), greater<int>());
        
        // Sort evens in ascending order
        sort(even.begin(), even.end());

        // Merge back into arr
        int idx = 0;
        for (int x : odd) arr[idx++] = x;
        for (int x : even) arr[idx++] = x;
    }
};
