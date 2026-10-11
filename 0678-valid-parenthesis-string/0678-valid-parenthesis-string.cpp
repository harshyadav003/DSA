// class Solution {
// public:
//     bool check(string &s,int i,int cnt){
//         int n=s.size();
//         if(cnt<0) return false;
//         if(i==n) return cnt==0;//true
//         if(s[i]=='(') return check(s,i+1,cnt+1);
//         if(s[i]==')') return check(s,i+1,cnt-1);
//         // for *
//         return check(s,i+1,cnt+1) || check(s,i+1,cnt-1) ||check(s,i+1,cnt);
//     }
//     bool checkValidString(string s) {
//         return check(s,0,0);
//     }
// };

//optimized:
class Solution {
public:
    
    bool checkValidString(string s) {
    int n=s.size();
    int max=0;
    int min=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') {
            min++;
            max++;
        }
        else if(s[i]==')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }
        if(min<0) min=0;
        if(max<0) return false;
    }
    return min==0;
    }
};