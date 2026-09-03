class Solution {
public:
    void generate(int n, string curr, vector<string>& ans){
        int open = count(curr.begin(), curr.end(), '(');
        int close = count(curr.begin(), curr.end(), ')');

        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }
   
       if(open < n)  generate(n,curr+"(",ans);
        
       if( close< open ){
        generate(n,curr+")",ans);
    }
   
}
    vector<string> generateParenthesis(int n) {
        string curr; vector<string> ans;
        generate(n,curr,ans);
        return ans;
    }
};