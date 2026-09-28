class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
         vector<int> temp;
        for(int i=0;i<nums.size();i++){
            
            ans^=nums[i];
          
        }
        long long bit = (long long)ans & -(long long)ans;
        int group1=0;
        int group2=0;
        for(int i=0;i<nums.size();i++){
            if((bit & nums[i]) == 0){
                group1^=nums[i];
            }
            else{
                group2^=nums[i];
            }
        }
        temp.push_back(group1);
        temp.push_back(group2);
        return temp;
    }
};