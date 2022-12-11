class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res=0;
        for(int row=0; row<grid.size(); row++){
            sort(grid[row].begin(),grid[row].end());
        }
        vector<int> sum(grid[0].size(),INT_MIN);
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[row].size(); col++){
                sum[col] = max(grid[row][col],sum[col]);
            }
        }
        for(int element : sum) res += element;
        return res;
    }
};