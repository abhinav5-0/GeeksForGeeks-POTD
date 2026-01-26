import java.util.*;

class Solution {
    
    void solve(int idx, int[] arr, List<List<Integer>> ans) {
        if (idx == arr.length) {
            List<Integer> temp = new ArrayList<>();
            for (int x : arr) temp.add(x);
            ans.add(temp);
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            swap(arr, idx, i);
            solve(idx + 1, arr, ans);
            swap(arr, idx, i); // backtrack
        }
    }

    void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public List<List<Integer>> permute(int[] arr) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(0, arr, ans);
        return ans;
    }
}
