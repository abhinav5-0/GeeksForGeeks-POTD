class Solution {
    
    void dfs(Node root, int k, ArrayList<Integer> path, int[] count) {
        if(root == null) return;
        
        path.add(root.data);
        
        int sum = 0;
        for(int i = path.size() - 1; i >= 0; i--) {
            sum += path.get(i);
            if(sum == k) count[0]++;
        }
        
        dfs(root.left, k, path, count);
        dfs(root.right, k, path, count);
        
        path.remove(path.size() - 1);
    }
    
    public int sumK(Node root, int k) {
        ArrayList<Integer> path = new ArrayList<>();
        int[] count = new int[1];
        
        dfs(root, k, path, count);
        
        return count[0];
    }
}
