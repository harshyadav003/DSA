
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = nums[n / 2];
        long long cnt = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < mid) {
                cnt += (long long)mid - nums[i];
            }
            else if(nums[i] > mid) {
                cnt += (long long)nums[i] - mid;
            }
        }

        return cnt;
    }
};
