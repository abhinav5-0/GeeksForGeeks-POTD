import java.util.*;

class Solution {
    public boolean canFinish(int n, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++) adj.add(new ArrayList<>());
        
        int[] indegree = new int[n];
        
        // Build graph
        for(int[] p : prerequisites) {
            adj.get(p[1]).add(p[0]);
            indegree[p[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        
        // Add nodes with 0 indegree
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.add(i);
        }
        
        int count = 0;
        
        while(!q.isEmpty()) {
            int node = q.poll();
            count++;
            
            for(int neigh : adj.get(node)) {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.add(neigh);
            }
        }
        
        return count == n;
    }
}
