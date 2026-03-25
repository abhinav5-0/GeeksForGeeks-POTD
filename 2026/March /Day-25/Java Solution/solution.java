import java.util.*;

class Solution {
    public List<Integer> minHeightRoots(int V, int[][] edges) {
        if (V == 1) return Arrays.asList(0);

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());

        int[] degree = new int[V];

        // Build graph
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        Queue<Integer> q = new LinkedList<>();

        // Push all leaf nodes
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1)
                q.offer(i);
        }

        int remaining = V;

        // Remove leaves level by level
        while (remaining > 2) {
            int size = q.size();
            remaining -= size;

            while (size-- > 0) {
                int node = q.poll();

                for (int neighbor : adj.get(node)) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        q.offer(neighbor);
                }
            }
        }

        return new ArrayList<>(q);
    }
}
