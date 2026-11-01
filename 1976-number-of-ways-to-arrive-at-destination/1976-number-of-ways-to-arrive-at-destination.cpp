class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>> adj(n);

for(auto it : roads) {
    adj[it[0]].push_back({it[1], it[2]});
    adj[it[1]].push_back({it[0], it[2]});
}
       priority_queue<pair<long long,int>,
               vector<pair<long long,int>>,
               greater<pair<long long,int>>> pq;
               
               vector<long long> dist(n, LLONG_MAX);
               vector<int> way(n,0); 
dist[0]=0;
way[0]=1;
pq.push({0, 0});

        
        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;

                if(dis+edw<dist[adjnode]){
                        dist[adjnode]=dis+edw;
                        pq.push({edw+dis,adjnode});
                        way[adjnode]=way[node];
                }
                else if(dis+edw==dist[adjnode]){
                    way[adjnode]=(way[adjnode]+way[node])%(int)(1e9+7);
                }
            }
        }
        return way[n-1];
    }
};