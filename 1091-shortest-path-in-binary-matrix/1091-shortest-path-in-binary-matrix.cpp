// class Solution {
// public:
//     bool dfs(int i,int j, vector<vector<int>> &vis,vector<vector<int>>& grid,int &ans,int cnt){
//         int n=grid.size();
//         int m=grid[0].size();
//         if(i == n-1 && j == m-1){
//     ans = min(ans, cnt);
//     return true;
// }
// if(cnt >= ans) return false;
//          int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//         int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
//         vis[i][j]=1;
//         for(int d=0;d<8;d++){
//             int r=i+drow[d];
//             int c=j+dcol[d];
//             if(r>=0 && c>=0 && r < n && c < m && grid[r][c] == 0 && vis[r][c] == 0){
//                 dfs(r,c,vis,grid,ans,cnt+1);
//             }
//         }
//         vis[i][j]=0;
//         return false;
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//          int n=grid.size();
//         int m=grid[0].size();
//          if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
//             return -1;
         
//            int ans = INT_MAX;
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//          dfs(0, 0, vis, grid, ans, 1);

//         return ans == INT_MAX ? -1 : ans;
//     }
// };   // will give TLE


// class Solution {
// public:
    
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//          int n=grid.size();
//         int m=grid[0].size();
//          if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
//             return -1;
         
           
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//          queue<pair<int,int>> q;q.push({0, 0});
//         vis[0][0] = 1;
//         int cnt = 1;

//         int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//         int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
//         while(!q.empty()){
//            int size = q.size();

//             for(int i=0;i<size;i++){
//                 // auto  node = q.front();
//                 //OR
//                 pair<int,int> node = q.front();
//                 q.pop();

//                 int r = node.first;
//                 int c = node.second;

//                 if (r == n-1 && c == m-1)
//                     return cnt;
//                 for (int d = 0; d < 8; d++) {
//                     int nr = r + drow[d];
//                     int nc = c + dcol[d];

//                     if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
//                         grid[nr][nc] == 0 && vis[nr][nc] == 0) {
//                         vis[nr][nc] = 1;
//                         q.push({nr, nc});
//                     }
//                 }
//                 }
//                  cnt++;
//             }
        
// return -1;
//         }


   
// };


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        if (n == 1 && m == 1) return 1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n-1 && c == m-1)
                return dis;

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < m &&
                    grid[newr][newc] == 0 &&
                    dis + 1 < dist[newr][newc]) {

                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};