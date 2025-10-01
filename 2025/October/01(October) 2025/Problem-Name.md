# All Unique Permutations of an Array

**Difficulty:** Medium  
**Accuracy:** 52.85%  
**Submissions:** 48K+  
**Points:** 4  
**Average Time:** 15m  

---

## Problem Statement

Given an array `arr[]` that may contain duplicates, find all possible distinct permutations of the array in **sorted order**.

> **Note:** A sequence A is greater than sequence B if there is an index `i` for which `Aj = Bj` for all `j < i` and `Ai > Bi`.

---

## Examples

### Example 1
**Input:**  
`arr[] = [1, 3, 3]`

**Output:**  
```
[[1, 3, 3], [3, 1, 3], [3, 3, 1]]
```

**Explanation:**  
These are the only possible distinct permutations for the given array.

---

### Example 2
**Input:**  
`arr[] = [2, 3]`

**Output:**  
```
[[2, 3], [3, 2]]
```

**Explanation:**  
These are the only possible distinct permutations for the given array.

---

## Constraints
- `1 ≤ arr.size() ≤ 9`

---

## Approach

1. Sort the array to maintain lexicographic order.
2. Use backtracking to generate all permutations.
3. Keep track of visited elements with a `used[]` boolean array.
4. Skip duplicates by ensuring that for each recursive call, if two numbers are equal, we only use the first unused one.
5. Store each valid permutation into the result.

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(arr.size(), false);

        sort(arr.begin(), arr.end()); // ensure sorted order
        backtrack(arr, result, current, used);
        return result;
    }

private:
    void backtrack(vector<int>& arr, vector<vector<int>>& result,
                   vector<int>& current, vector<bool>& used) {
        if (current.size() == arr.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue;

            // Skip duplicates: if arr[i] == arr[i-1] and i-1 not used, skip
            if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;

            used[i] = true;
            current.push_back(arr[i]);

            backtrack(arr, result, current, used);

            // backtrack
            current.pop_back();
            used[i] = false;
        }
    }
};
```

---

## Example Run

```cpp
int main() {
    Solution sol;
    vector<int> arr = {1, 3, 3};
    auto ans = sol.uniquePerms(arr);

    for (auto &perm : ans) {
        for (int x : perm) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
```

**Output:**
```
1 3 3
3 1 3
3 3 1
```

---

✅ Works for duplicates  
✅ Produces **unique permutations**  
✅ Returns them in **sorted order**
