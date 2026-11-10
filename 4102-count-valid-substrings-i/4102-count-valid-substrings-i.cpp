class Solution {
public:
    long long countValidSubstrings(string s) {
    int l=0, r=0;
     int n=s.size();
      long long cnt=0;
      
     while(r<n){
         if(r-l+1>=3 && s[r-2]=='a' && s[r-1]=='b' && s[r]=='c') {
                l=r-1;
            }
            else {
                cnt += (r-l+1);
            
            r++;}
     }
     return  cnt;
    }
};
