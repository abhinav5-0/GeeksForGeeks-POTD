class Solution {
    int n, m;
    
    boolean dfs(char[][] mat, String word, int i, int j, int idx) {
        if (idx == word.length())
            return true;
        
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        
        if (mat[i][j] != word.charAt(idx))
            return false;
        
        char temp = mat[i][j];
        mat[i][j] = '#';  // mark visited
        
        boolean found =
            dfs(mat, word, i+1, j, idx+1) ||
            dfs(mat, word, i-1, j, idx+1) ||
            dfs(mat, word, i, j+1, idx+1) ||
            dfs(mat, word, i, j-1, idx+1);
        
        mat[i][j] = temp; // backtrack
        return found;
    }
    
    public boolean isWordExist(char[][] mat, String word) {
        n = mat.length;
        m = mat[0].length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word.charAt(0)) {
                    if (dfs(mat, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
}
