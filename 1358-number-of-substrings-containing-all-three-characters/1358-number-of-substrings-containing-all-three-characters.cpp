class Solution {
public:
    int numberOfSubstrings(string s) {
        //m1:
        // int cnt=0;
        // int n=s.size();
        // for(int i=0;i<n;i++){
        //     vector<int> hash(3);
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'a']=1;
        //         if(hash[0]+hash[1]+hash[2]==3) {cnt+=(n-j);break;}
        //     }
        // }
        // return cnt;

        // m2:
        // int l=0;
        // int r=0;
        // int n=s.size();
        // int cnt=0;
        // vector<int> hash(3);
        // while(r<n){
        //     hash[s[r]-'a']++;
        //     while(hash[0] > 0 && hash[1] > 0 && hash[2] > 0){  
        //     cnt += (n-r);

        //    hash[s[l]-'a']--;
        //    l++;
        // }
        //     r++;

        // }
        // return cnt;

        // m3:
       vector<int> lastseen(3, -1);
        int cnt=0;
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1) cnt+=(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
        }
        return cnt;
    }
};