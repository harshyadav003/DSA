class Solution {
public:
    int totalFruit(vector<int>& f) { //fruits=f
        int n=f.size();
        int l=0;
        int r=0;
        int maxlen=0;
        map<int,int> mpp;
        while(r<n){
            mpp[f[r]]++;
            if(mpp.size()>2){
               
                    mpp[f[l]]--;
                    if(mpp[f[l]]==0) mpp.erase(f[l]);
                    l++;
                               
            }
            if(mpp.size()<=2) maxlen=max(maxlen,r-l+1);
                r++;
        }
        return maxlen;
    }
};