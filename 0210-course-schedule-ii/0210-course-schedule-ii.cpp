class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& prerequisites,vector<int>& vis, vector<int>& pathVis,vector<int> &ans){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto adjnode: prerequisites[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode, node, prerequisites, vis, pathVis,ans)==true)
            return true;
            }
            else if(pathVis[adjnode]){
                return true;
            }
        }
         pathVis[node] = 0;
         ans.push_back(node);
       return false; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        
for(auto it : prerequisites) {
    int node = it.back(); 
    int parent = it.front();
    adj[node].push_back(parent);
}
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis,pathVis,ans)==true) return {};
             }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};