class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= intervals[i-1][1]){
                if(intervals[i][1] <= intervals[i-1][1]){
                    intervals[i][1] = intervals[i-1][1];
                }
                intervals[i][0] = intervals[i-1][0];
            }
        }
        for(int i=0; i<intervals.size(); i++){
            if(i==intervals.size()-1){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0] != intervals[i+1][0]){
               ans.push_back(intervals[i]);
            }
        }
        return ans;       
    }
};