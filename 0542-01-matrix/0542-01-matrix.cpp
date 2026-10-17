class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        queue<pair<int, int>> q;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(r, vector<int>(c, 0));

       vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
       
        while (!q.empty()) {
            
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int i = q.front().first;
            int j = q.front().second;
            q.pop();
                for (int d = 0; d < 4; d++) {
                    int nrow = i + delrow[d];
                    int ncol = j + delcol[d];
                    if (nrow >= 0 && ncol >= 0 && nrow < r && ncol < c) {
                        if (mat[nrow][ncol] == 0 && vis[nrow][ncol] == 0) {
                          
                            ans[nrow][ncol] = ans[i][j] + 1;
                            vis[nrow][ncol] = 1;
                             q.push({nrow, ncol});
                        } else if (mat[nrow][ncol] == 1 &&
                                   vis[nrow][ncol] == 0) {
                           ans[nrow][ncol] = ans[i][j] + 1;
                            vis[nrow][ncol] = 1;
                             q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
        return ans;
    }
};