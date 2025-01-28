# Permutations of a String

## Problem Statement
Given a string `s`, which may contain duplicate characters, the task is to generate and return an array of all unique permutations of the string. The output can be in any order.

### Examples

**Input:**  
`s = "ABC"`  
**Output:**  
`["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]`  
**Explanation:**  
The string `"ABC"` has 6 unique permutations.

---

**Input:**  
`s = "ABSG"`  
**Output:**  
`["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]`  
**Explanation:**  
The string `"ABSG"` has 24 unique permutations.

---

**Input:**  
`s = "AAA"`  
**Output:**  
`["AAA"]`  
**Explanation:**  
No other unique permutations can be formed as all characters are the same.

---

## Constraints
- \(1 \leq s.size() \leq 9\)
- \(s\) contains only uppercase English alphabets.

---

## Solution Overview
The solution is implemented using a backtracking approach with the following steps:
1. **Sorting**: The input string is sorted to group duplicate characters, enabling effective skipping of duplicates during the recursive traversal.
2. **Backtracking**: A recursive function is used to generate all permutations, skipping duplicate characters and ensuring that each character is used only once per recursive call.
3. **Set for Uniqueness**: A `set` is used to store unique permutations and eliminate duplicates automatically.
4. **Conversion to Vector**: The unique permutations are returned as a vector for output.

---

## Code Example

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> findPermutation(string &s) {
        set<string> uniquePermutations;
        string currentPermutation;
        vector<bool> used(s.size(), false);
        sort(s.begin(), s.end());

        function<void()> backtrack = [&]() {
            if (currentPermutation.size() == s.size()) {
                uniquePermutations.insert(currentPermutation);
                return;
            }
            for (int i = 0; i < s.size(); ++i) {
                if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) continue;
                used[i] = true;
                currentPermutation.push_back(s[i]);
                backtrack();
                used[i] = false;
                currentPermutation.pop_back();
            }
        };

        backtrack();
        return vector<string>(uniquePermutations.begin(), uniquePermutations.end());
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
