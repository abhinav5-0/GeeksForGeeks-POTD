class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        unordered_set<int> elementsInMat2;

        // Flatten mat2 and insert elements into the hash set
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                elementsInMat2.insert(mat2[i][j]);
            }
        }

        int count = 0;

        // For every element in mat1, check if (x - a) exists in mat2
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int complement = x - mat1[i][j];
                if (elementsInMat2.find(complement) != elementsInMat2.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};
