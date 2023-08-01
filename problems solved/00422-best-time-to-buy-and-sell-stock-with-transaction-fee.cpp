class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2));
        dp[n][0] = dp[n][1] = dp[n+1][0] = dp[n+1][1] = 0;

        for(int day=n-1; day>=0; day--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy) profit = max(-prices[day]+dp[day+1][0],dp[day+1][1]);
                else profit = max(prices[day]+dp[day+1][1] - fee,dp[day+1][0]);
                dp[day][buy] = profit;
            }
        }
		return dp[0][1];
    }
};