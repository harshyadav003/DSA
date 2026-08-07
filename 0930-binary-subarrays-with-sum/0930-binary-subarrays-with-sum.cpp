// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//        int x=0;
//        int y=0;
//        int n=nums.size();       
//        for(int i=0;i<n;i++){
//         int sum=0;
//          for(int j=i;j<n;j++){
//             sum+=nums[j];
//             if(sum<=goal) x++;
//             if(sum<=goal-1) y++;
//          }        
//        }
//        return x-y;
//     }
// };

class Solution {
public:
 int s(vector<int>& nums, int goal) {
        if(goal<0) return 0;
       int l=0;
       int r=0;
       int n=nums.size();
       int cnt=0;int sum=0;
       while(r<n){        
        sum+=nums[r];
      
        while(sum>goal){
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
        r++;
       }
       return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return s(nums,goal)-s(nums,goal-1);
    }
};