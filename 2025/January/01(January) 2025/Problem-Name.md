

### Problem: Print Anagrams Together

#### Difficulty: Medium

#### Description:
Given an array of strings, group all strings that are anagrams. The groups must:
- Appear in the order of their first occurrence in the input array.
- Contain strings sorted lexicographically within each group.

#### Constraints:

- The size of the array (\( arr \)) is between 1 and 100, inclusive.  
- The length of each string in the array (\( arr[i] \)) is between 1 and 10, inclusive.

---

### Examples

**Example 1:**
```text
Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
```

**Example 2:**
```text
Input: arr[] = ["no", "on", "is"]
Output: [["is"], ["no", "on"]]
```

**Example 3:**
```text
Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
Output: [["abc", "bac", "cab"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
```

---

### Solution

#### Approach:
1. Use a hash map to group strings by their sorted version.
2. Maintain the order of groups based on their first appearance in the input array.
3. Ensure strings within each group are sorted lexicographically.

---

### Implementation

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

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

        // Collect the groups in order of first appearance
        vector<vector<string>> result;
        unordered_set<string> processedKeys;

        for (const string& str : arr) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            if (processedKeys.find(sortedStr) == processedKeys.end()) {
                auto& group = groupedAnagrams[sortedStr];
                sort(group.begin(), group.end()); // Ensure lexicographic order
                result.push_back(group);
                processedKeys.insert(sortedStr);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> result = solution.anagrams(arr);

    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
```

---

### Explanation

1. **Hash Map for Grouping**:
   - Each string is sorted alphabetically to generate a key.
   - Anagrams will have the same sorted key.

2. **Maintaining Order**:
   - Iterate over the input array to collect groups in the order of their first appearance.

3. **Sorting Within Groups**:
   - Sort each group lexicographically before adding it to the result.

---

### Example Execution

#### Input:
```text
arr[] = ["act", "god", "cat", "dog", "tac"]
```

#### Execution Steps:
1. **Group by Sorted Key**:
   ```text
   "act" -> "act", "god" -> "dgo", "cat" -> "act", "dog" -> "dgo", "tac" -> "act"
   Grouped Map: { "act": ["act", "cat", "tac"], "dgo": ["god", "dog"] }
   ```

2. **Collect Groups in Order**:
   ```text
   Result: [["act", "cat", "tac"], ["god", "dog"]]
   ```

#### Output:
```text
[ ["act", "cat", "tac"], ["god", "dog"] ]
```

--- 

