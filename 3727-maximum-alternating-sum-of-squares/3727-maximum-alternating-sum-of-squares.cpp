class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size();
        vector<long long> arr;
        for(long long i=0;i<n;i++){
            arr.push_back(1LL*nums[i]*nums[i]);
        }
        sort(arr.rbegin(),arr.rend());
        long long scoremin=0;
        long long scoremax=0;

        for(long long i=0;i<n;i++){
            if(i>=ceil(n/2.0))           
            scoremin=scoremin+(arr[i]);
            else
            scoremax=scoremax+(arr[i]);
        }
return scoremax-scoremin;
    }
};