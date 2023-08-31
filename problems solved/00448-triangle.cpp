class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=i; j++){
                int bot = tri[i][j] + dp[i+1][j];
                int bot_right = tri[i][j] + dp[i+1][j+1];

                dp[i][j] = min(bot,bot_right);
            }
        }
        return dp[0][0];
    }
};