
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int cnt = INT_MAX;
        int ans = -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j],
                                         dist[via][j] + dist[i][via]);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            int tempcnt = 0;

            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) {
                    tempcnt++;
                }
            }

            if(tempcnt <= cnt) {
                cnt = tempcnt;
                ans = i;
            }
        }

        return ans;
    }
};
