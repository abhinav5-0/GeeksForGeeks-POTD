class Solution {
  public:
    void solve(int idx, vector<int>& arr, vector<vector<int>>& ans){
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }

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
