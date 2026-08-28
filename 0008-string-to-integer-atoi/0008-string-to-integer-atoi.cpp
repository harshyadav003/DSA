class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int sign=1;
        int flag=0;
        int signFlag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]<'0' || s[i]>'9') {
             if(flag == 0 && s[i] != ' ' && s[i] != '+' && s[i] != '-')
              return 0;
              }
            if(s[i] == ' ') {
               if(signFlag == 1 && flag == 0)
                   break;

                if(flag==1) break;

                   continue;
            }
            
            if(s[i] == '+' || s[i] == '-') {
                 if(flag == 1 || signFlag == 1) break; 
                 signFlag = 1; 
                 if(s[i] == '-') sign = -1; 
                 continue; 
                 }
            
            if(s[i]>='0' && s[i]<='9'){
                if(ans > INT_MAX/10)
             return sign == 1 ? INT_MAX : INT_MIN;


               if(ans == INT_MAX/10){
                int digit=s[i]-'0';
             if(sign == 1 && digit > 7)
               return INT_MAX;

            if(sign == -1 && digit > 8)
                return INT_MIN;
              }
                ans=10*ans+((s[i]-'0'));
                flag=1;
            }
                else if(flag==1 ) break;
        }
        
        return sign*ans;
    }
};