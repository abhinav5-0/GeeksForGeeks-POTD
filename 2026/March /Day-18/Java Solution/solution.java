class Solution {
    int moves = 0;

    int dfs(Node root) {
        if (root == null) return 0;

        int left = dfs(root.left);
        int right = dfs(root.right);

        moves += Math.abs(left) + Math.abs(right);

        return root.data + left + right - 1;
    }

    public int distCandy(Node root) {
        moves = 0;
        dfs(root);
        return moves;
    }
}
