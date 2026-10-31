#define P pair<int, pair<int, int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();    

          priority_queue<P, vector<P>, greater<P>> q;
      
       vector<vector<int>> minEffort(n, vector<int>(m, 1e9));

        minEffort[0][0] = 0;
        q.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            P it = q.top();
            q.pop();

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1)
                return effort;


if (effort > minEffort[r][c]) continue;


            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < m ) {
                   
                  int  neweffort=max(effort,
                        abs(heights[r][c] - heights[newr][newc]));
                    if(neweffort<minEffort[newr][newc]){
                        minEffort[newr][newc] = neweffort;
                        q.push({neweffort,{newr,newc}});
                    }
                }
            }
        
        }
        
        return 0;
    }
};