class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dp(rows,vector<int>(cols,0));

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(row==0) {dp[row][col] = mat[row][col]; continue;}
                int up = mat[row][col] + dp[row-1][col];
                int up_left = col-1>=0 ? mat[row][col] + dp[row-1][col-1] : 1e9; 
                int up_right = col+1<cols ? mat[row][col] + dp[row-1][col+1] : 1e9;
                dp[row][col] = min({up,up_left,up_right});
            }
        }
        return *min_element(dp[rows-1].begin(),dp[rows-1].end());
    }
};