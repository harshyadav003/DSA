class Solution {
public:
void cs(vector<int>& c, int i, int sum, int t,
            vector<int>& temp, vector<vector<int>>& ans) {

        if(sum == t) {
            ans.push_back(temp);
            return;
        }

        if(i == c.size() || sum > t)
            return;

        // Take
        temp.push_back(c[i]);
        cs(c, i + 1, sum + c[i], t, temp, ans);
        temp.pop_back();

        // Not Take
        i++;

        // Skip duplicates in NOT TAKE
        while(i < c.size() && c[i] == c[i - 1])
            i++;

        cs(c, i, sum, t, temp, ans);
    }     
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(),candidates.end()); // Sort the candidates to handle duplicates

        cs(candidates, 0, 0, target, temp, ans);

        
        return  ans;
    }
};