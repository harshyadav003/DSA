class Solution {
public:
    int candy(vector<int>& r) {//ratings
        int n=r.size();
        vector<int> arr(n,1);
        for(int i=1;i<n;i++){
            if(r[i-1]<r[i]){
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=n-1;i>=1;i--){
            if(r[i-1]>r[i]){
                arr[i-1] = max(arr[i-1], arr[i] + 1);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=arr[i];
        }
    return ans;
    }
};