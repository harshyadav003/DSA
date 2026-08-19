class Solution {
public:
#define ppi pair<int,int>
    vector<int> arrayRankTransform(vector<int>& arr) {
  vector<int> ans(arr.size());
        priority_queue<ppi,vector<ppi>,greater<ppi>> minh;
         for(int i=0;i<arr.size();i++){
            minh.push({arr[i],i}); 
         }
         int rank=0; int prev=1e9;
         while(!minh.empty()){
           int index=minh.top().second;
           int current=minh.top().first;
          
           if(current!=prev){
            rank++;
           }
           ans[index]=rank;
           prev=current;
           minh.pop();
         }
         return ans;
    }
};