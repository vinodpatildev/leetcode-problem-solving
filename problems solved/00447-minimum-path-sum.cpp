class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // vector<vector<int>> dp(rows,vector<int>(cols,-1));   
        vector<int> prev(cols,0), cur(cols,0);     
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(row==0 && col==0) {cur[col] = grid[row][col]; continue;}

                int top=1e9, left=1e9;
                if(row-1 >= 0) top = grid[row][col] + prev[col];
                if(col-1 >= 0) left = grid[row][col] + cur[col-1];

                int min_path_sum  = min(top,left);

                cur[col] = min_path_sum;
            }
            prev = cur;
        }
        return prev[cols-1];
    }
};