class Solution {
public:
    int numTilings(int n) {
        int md = 1e9 + 7;
        vector<long long> dp(n+3,0);
        dp[1] = 1, dp[2] = 2, dp[3] = 5;
        if(n<=3) return dp[n];
        for(int i=4; i<=n; i++) dp[i] = 2*dp[i-1] + dp[i-3], dp[i] %= md;
        return dp[n];
    }
};