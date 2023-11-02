class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res=1;
        sort(points.begin(),points.end());
        int prevEnd = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(prevEnd >= points[i][0]){
                prevEnd = min(prevEnd,points[i][1]);
                continue;
            }
            res++;
            prevEnd = points[i][1];
        }
        return res;
    }
};