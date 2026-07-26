class Solution {
public:
//BRUTE:
    // int longestOnes(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int maxlen=0;
    //     for(int i=0;i<n;i++){
    //         int zero=0;
    //         for(int  j=i;j<n;j++){
    //             if(nums[j]==0) zero++;
    //             if(zero<=k) {
    //                 int len = j-i+1;
    //                 maxlen=max(maxlen,len);
    //             }
    //             else{
    //                 break;//if no. of zero > k 
    //             }
    //         }
    //     }
    //     return maxlen;
    // }

//OPTIMIZATION:
int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxlen=0;
        int zero=0;
        while(r<n){
            if(nums[r]==0) zero++;
            while(zero>k){
                if(nums[l]==0) zero--;
                    l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};