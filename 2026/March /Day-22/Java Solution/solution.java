class Solution {
    public int orangesRot(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2)
                    q.offer(new int[]{i,j});
                else if(mat[i][j] == 1)
                    fresh++;
            }
        }
        
        int time = 0;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        while(!q.isEmpty() && fresh > 0){
            int size = q.size();
            time++;
            
            while(size-- > 0){
                int[] curr = q.poll();
                int x = curr[0], y = curr[1];
                
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1){
                        mat[nx][ny] = 2;
                        fresh--;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
}
