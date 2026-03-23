import java.util.*;

class Solution {
    public int longestCycle(int V, int[][] edges) {
        int[] next = new int[V];
        Arrays.fill(next, -1);

        // Build mapping
        for (int[] e : edges) {
            next[e[0]] = e[1];
        }

        int[] vis = new int[V];
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (vis[i] == 1) continue;

            Map<Integer, Integer> step = new HashMap<>();
            int node = i, cnt = 0;

            while (node != -1 && vis[node] == 0) {
                vis[node] = 1;
                step.put(node, cnt++);
                node = next[node];

                if (node != -1 && step.containsKey(node)) {
                    ans = Math.max(ans, cnt - step.get(node));
                    break;
                }
            }
        }

        return ans;
    }
}
