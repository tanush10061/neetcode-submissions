class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int i;
        for(i=0;i<n;i++){
            if(intervals[i][0]>newInterval[0]) break;
        }
        intervals.insert(intervals.begin()+i,newInterval);
        int curr_start=intervals[0][0];
        int curr_end=intervals[0][1];
        vector<vector<int>> ans;
        n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=curr_end){
                curr_end=max(intervals[i][1],curr_end);
            }
            else{
                ans.push_back({curr_start,curr_end});
                curr_start=intervals[i][0];
                curr_end=intervals[i][1];
            }
        }
        ans.push_back({curr_start,curr_end});
        return ans;
    }
};
