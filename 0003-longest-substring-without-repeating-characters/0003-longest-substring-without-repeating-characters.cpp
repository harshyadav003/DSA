class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         
         int maxi=0;
        
        for(int i=0;i<s.size();i++){
           unordered_set<char> st;
            for(int j=i;j<s.size();j++){
                if(st.find(s[j]) == st.end()){
                st.insert(s[j]); 
             maxi = max(maxi, (int)st.size());  
            } else{break;}
           
             }  
        
        }
        return maxi;
    }
};