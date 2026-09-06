class Solution {
public:
    void cs3(int i,int k,int sum, int n,vector<int> & temp,vector<vector<int>> & ans) {
        if(sum==n && temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        if(i==9) return;
        int arr[]={1,2,3,4,5,6,7,8,9};
        temp.push_back(arr[i]);
        cs3(i+1,k,sum+arr[i],n,temp,ans);
        temp.pop_back();

        cs3(i+1,k,sum,n,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>  temp;
        cs3(0, k, 0, n, temp, ans);
        return ans;
    }
};