class Solution {
public:
int ans(vector<int>& nums, int k){   
        int l=0;
        int r=0;
        int good=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            good+=r-l+1;
            r++;
        }
        return  good;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
return ans(nums,k)-ans(nums,k-1);
    }
};