import java.util.*;

class Solution {
    public int minSwaps(int[] arr) {
        int n = arr.length;
        
        int[][] temp = new int[n][2];
        for(int i = 0; i < n; i++) {
            temp[i][0] = arr[i];
            temp[i][1] = i;
        }
        
        Arrays.sort(temp, Comparator.comparingInt(a -> a[0]));
        
        boolean[] visited = new boolean[n];
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            if(visited[i] || temp[i][1] == i)
                continue;
            
            int cycle_size = 0;
            int j = i;
            
            while(!visited[j]) {
                visited[j] = true;
                j = temp[j][1];
                cycle_size++;
            }
            
            if(cycle_size > 1)
                swaps += (cycle_size - 1);
        }
        
        return swaps;
    }
}
