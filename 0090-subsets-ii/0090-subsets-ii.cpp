class Solution {
public:
void ss(int i,vector<int> &num,vector<int> & temp,vector<vector<int>> &ans){
	if(i==num.size()){
		ans.push_back(temp);
		return ;
	}
	temp.push_back(num[i]);
	ss(i+1,num,temp,ans);
	temp.pop_back();
    
    int j=i+1;
    while(j<num.size() && num[j]==num[i]) j++;
    

	ss(j,num,temp,ans); //i+1+1

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       vector<vector<int>> ans;
	   vector<int> temp;
	ss(0,nums,temp,ans);
	
	return ans;
    }
};