class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int refrence=*max_element(nums.begin(),nums.end());
        int cnt=0;
        
        for(int i=0;i<n;i++){
            while(nums[i]<refrence){
                nums[i]++;
                cnt++;
            }
        }
        return cnt;
    }
};