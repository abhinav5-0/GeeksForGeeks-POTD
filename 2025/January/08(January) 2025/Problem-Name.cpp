class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        int count = 0;

        // Step 2: Use the three-pointer technique
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    // If arr[i] + arr[j] > arr[k], then all pairs between i and j are valid
                    count += (j - i);
                    --j; // Move j to check smaller pairs
                } else {
                    ++i; // Move i to increase the sum
                }
            }
        }

        return count;
    }
};
