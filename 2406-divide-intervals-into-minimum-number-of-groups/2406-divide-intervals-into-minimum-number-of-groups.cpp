class Solution {
public:
    int minGroups(vector<vector<int>>& it) { //intervals
        int count=0;
        int n=it.size();
        sort(it.begin(),it.end());
        // it[i][0] = left point
        // it[i][1] = right point
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            int left=it[i][0];
            
            if(!pq.empty() && pq.top()<left){
                pq.pop();
            }
            pq.push(it[i][1]);
        }
        return pq.size();
    }
};