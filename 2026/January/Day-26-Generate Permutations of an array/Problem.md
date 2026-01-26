
📌 Problem

Given an array arr[] of unique elements, generate all possible permutations of the array.

You can return permutations in any order.


---

✅ Approach (Backtracking + Swap)

We fix one position at a time and try putting every remaining element there.

Start from index 0

Swap current index with every index i >= idx

Recurse for next index

Backtrack by swapping back



---

✅ C++ Code (GFG Format)

class Solution {
  public:
    void solve(int idx, vector<int>& arr, vector<vector<int>>& ans){
        // base case: when we fixed all positions
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }

        // try every element at position idx
        for(int i = idx; i < arr.size(); i++){
            swap(arr[idx], arr[i]);
            solve(idx + 1, arr, ans);
            swap(arr[idx], arr[i]); // backtrack
        }
    }

    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> ans;
        solve(0, arr, ans);
        return ans;
    }
};


---

⏱️ Complexity

Time: O(n! * n) (because total permutations = n! and each takes O(n) to store)

Space: O(n) recursion stack (excluding output)



---
