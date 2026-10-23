// class Solution {
// public:
//   bool dfs(int node ,int col,vector<int> & colorv,vector<vector<int>>& graph){
//         colorv[node]=col;
//         for(auto it:graph[node]){
//             if(colorv[it]==-1){
//                 if(dfs(it,!col,colorv,graph)==false) return false;
//             }
//             else if(colorv[it]==col) return false;
//         }
//         return true;
//   }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int> colorv(n,-1);
//         for(int i=0;i<n;i++){
//             if(colorv[i]==-1){
//                 if(dfs(i,0,colorv,graph)==false) return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
  bool bfs(int start ,int node,vector<int> & color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
        }
        return true;
  }
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int> color(n,-1);
       for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(bfs(i,n,color,graph)==false) return false;
        }
       }
       return true;
    }
};