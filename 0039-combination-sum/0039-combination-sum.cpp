class Solution {
public:
   void cs(vector<int>& c, int i, int sum, int t,
            vector<int>& temp, vector<vector<int>>& ans){
            
            if(sum==t){
                ans.push_back(temp);
                return ;
            }
             if(i == c.size() || sum>t)
            return;

            temp.push_back(c[i]);
            cs(c,i,sum+c[i],t,temp,ans); //i bcz repetition allowed
            temp.pop_back();

             cs(c,i+1,sum,t,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> temp;

        cs(candidates, 0, 0, target, temp, ans);

        
        return  ans;
    }
};