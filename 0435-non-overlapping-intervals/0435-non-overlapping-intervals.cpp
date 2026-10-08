class Solution {
public:
 static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
   int n=start.size();
    vector<pair<int,int>> ans;
     for(int i=0;i<n;i++){
        ans.push_back({start[i], end[i]});
    }
     sort(ans.begin(), ans.end(), cmp);
      int cnt = 1;
      int lastend=ans[0].second;
      for(int i=1;i<n;i++){
          if(ans[i].first>=lastend){ //equal case we have to count here only!! Note that intervals which only touch at a point are non-overlapping.
              cnt++;
              lastend=ans[i].second;
          }
      }
      return cnt;

}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);  
        }
        int count= maximumMeetings(start,end);
        return intervals.size()-count;
    }
};