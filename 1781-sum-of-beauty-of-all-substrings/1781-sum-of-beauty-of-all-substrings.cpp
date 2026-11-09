class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
         int ans=0;
       
        for(int k=0;k<n;k++){  
             unordered_map<char,int> mpp;      
        for(int i=k;i<n;i++){
             mpp[s[i]]++;
        
       
        int maxi=INT_MIN;
        int mini=INT_MAX;
             for(auto it : mpp){
            if(it.second>maxi) maxi=max(maxi,it.second);
            if(it.second<mini) mini=min(mini,it.second);
        }
        ans+=(maxi-mini);
        }
        }
        return ans;
    }
};