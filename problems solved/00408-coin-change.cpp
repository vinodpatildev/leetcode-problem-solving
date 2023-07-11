class Solution {
    int f(int index, int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(index == 0) {
            if(amount % coins[0] == 0) return amount / coins[index];
            else return 1e9;
        }
        if(dp[index][amount] != -1) return dp[index][amount];

        int notPick = f(index-1, amount, coins,dp);
        int pick = 1e9;
        if(coins[index]<=amount) pick = 1 + f(index,amount-coins[index],coins,dp);

        return dp[index][amount] = min(notPick, pick);
    }
public:
    int coinChange(vector<int>& coins,int amount) {
        int N = coins.size();
        vector<vector<int>> dp(N,vector<int>(amount+1,-1));
        vector<int> prev(amount+1,1e9), cur(amount+1);

        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0) prev[a] = a / coins[0];
        }
        for(int index = 1; index<=N-1; index++){
            for(int a = 0; a<=amount; a++){
                int notPick = prev[a];
                int pick = 1e9;
                if(coins[index]<=a) pick = 1 + cur[a-coins[index]];

                cur[a] = min(notPick, pick);
            }
            prev = cur;
        }


        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};