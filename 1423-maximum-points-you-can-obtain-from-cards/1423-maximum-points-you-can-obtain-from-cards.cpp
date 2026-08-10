class Solution {
public:
    int maxScore(vector<int>& c, int k) { //c=cardpoints
        int n=c.size();
        int l=0;
        int r=0;
        int minsum=INT_MAX;
        int sum=0;
        while(r<n){
            sum+=c[r];
            while((r-l+1>(n-k))){
                sum-=c[l];
                l++;
            }

           if (r-l+1 == n-k) minsum = min(minsum, sum);
            
            r++;
        }
        int totalSum = accumulate(c.begin(), c.end(), 0);
        return totalSum-minsum;
    }
};