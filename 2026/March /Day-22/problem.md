# 🍊 Rotten Oranges

## 🧩 Problem Statement

Given a matrix `mat[][]`, where each cell can have values:

* `0` → Empty cell
* `1` → Fresh orange
* `2` → Rotten orange

A rotten orange at position `(i, j)` can rot adjacent fresh oranges at positions:

* `(i-1, j)` (up)
* `(i+1, j)` (down)
* `(i, j-1)` (left)
* `(i, j+1)` (right)

Each rotting process takes **1 unit time**.

### 🎯 Goal

Return the **minimum time required** so that all oranges become rotten.

If it is impossible to rot all oranges, return `-1`.

---

## 📥 Example 1

**Input:**

```
mat[][] = [[2,1,0,2,1],
           [1,0,1,2,1],
           [1,0,0,2,1]]
```

**Output:**

```
2
```

**Explanation:**
All fresh oranges become rotten in 2 time frames.

---

## 📥 Example 2

**Input:**

```
mat[][] = [[2,1,0,2,1],
           [0,0,1,2,1],
           [1,0,0,2,1]]
```

**Output:**

```
-1
```

**Explanation:**
Some oranges cannot be reached, so all cannot rot.

---

## ⚙️ Constraints

* `1 ≤ mat.size() ≤ 500`
* `1 ≤ mat[0].size() ≤ 500`
* `mat[i][j] ∈ {0, 1, 2}`

---

## 💡 Approach (BFS - Multi Source)

This is a classic **Breadth First Search (BFS)** problem.

### 🔹 Steps:

1. Push all rotten oranges `(value = 2)` into a queue.
2. Count total fresh oranges.
3. Perform BFS:

   * For each rotten orange, rot its adjacent fresh oranges.
   * Decrease fresh count.
4. Track time using levels of BFS.
5. If fresh oranges remain → return `-1`, else return time.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n × m)`
* **Space Complexity:** `O(n × m)`

---

## 💻 C++ Code

```cpp
class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2)
                    q.push({i,j});
                else if(mat[i][j] == 1)
                    fresh++;
            }
        }
        
        int time = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        while(!q.empty() && fresh > 0){
            int size = q.size();
            time++;
            
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1){
                        mat[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
};
```

---

## ☕ Java Code

```java
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
```

---

## 🐍 Python Code

```python
from collections import deque

class Solution:
    def orangesRot(self, mat):
        n, m = len(mat), len(mat[0])
        q = deque()
        fresh = 0
        
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 2:
                    q.append((i, j))
                elif mat[i][j] == 1:
                    fresh += 1
        
        time = 0
        directions = [(-1,1),(1,0),(0,-1),(0,1)]
        
        while q and fresh > 0:
            for _ in range(len(q)):
                x, y = q.popleft()
                
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    
                    if 0 <= nx < n and 0 <= ny < m and mat[nx][ny] == 1:
                        mat[nx][ny] = 2
                        fresh -= 1
                        q.append((nx, ny))
            time += 1
        
        return time if fresh == 0 else -1
```

---

## 🚀 Key Takeaways

* Multi-source BFS is the key idea.
* Process level-by-level to track time.
* Similar to "spread" problems (infection, fire, etc.).
