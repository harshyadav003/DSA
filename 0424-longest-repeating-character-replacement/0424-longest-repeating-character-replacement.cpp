class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int n=s.size();
        vector<int> hash(26);
            int maxfreq=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            int changes=(r-l+1)-maxfreq;
            if(changes>k){
               hash[s[l]-'A']--;
            //    if(hash[s[r]-'A']==0) hash.pop(hash[s[r]-'A']);
                l++;
            }
            if(changes<=k) maxlen=max(maxlen,r-l+1);

            r++;
            
        }
        return maxlen;
    }
};