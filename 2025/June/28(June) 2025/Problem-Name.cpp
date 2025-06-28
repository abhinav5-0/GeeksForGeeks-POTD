#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // Step 1: Sort b[]
        sort(b.begin(), b.end());

        vector<int> result;
        for (int num : a) {
            // Step 2: Use upper_bound to find count of elements <= num
            int count = upper_bound(b.begin(), b.end(), num) - b.begin();
            result.push_back(count);
        }

        return result;
    }
};
