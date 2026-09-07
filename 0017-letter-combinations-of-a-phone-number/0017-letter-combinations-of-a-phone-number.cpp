// class Solution {
// public:
//   void fn(int i,int j,string digit,string s,string combos[],vector<string> &ans){
        
//          if(i==digit.size()){
//             ans.push_back(s);
//             return;
//          }
       
//         int d = digit[i] - '0';

//         if(j == combos[d].size()) { return; }

//          s.push_back(combos[d][j]);
//          fn(i+1,0,digit,s,combos,ans);
//          s.pop_back();

//          fn(i,j+1,digit,s,combos,ans); 


//   }
//     vector<string> letterCombinations(string digits) {
//         // string s = "";
//         string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string> ans;
//         fn(0,0,digits,"",combos,ans);
//         return ans;
//     }
// };




class Solution {
public:
  void fn(int i,string digit,string s,string combos[],vector<string> &ans){
        
         if(i==digit.size()){
            ans.push_back(s);
            return;
         }
       
        int d = digit[i] - '0';

        for(int j=0;j<combos[d].size();j++){
            fn(i+1,digit,s + combos[d][j],combos,ans);
        }


  }
    vector<string> letterCombinations(string digits) {
        // string s = "";
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        fn(0,digits,"",combos,ans);
        return ans;
    }
};