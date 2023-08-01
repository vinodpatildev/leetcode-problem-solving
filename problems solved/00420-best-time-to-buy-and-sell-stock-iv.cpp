class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2,vector(k+1,0));
        vector<vector<int>> cur(2,vector(k+1,0));
        for(int day=n-1; day>=0; day--){
            for(int buy=1; buy>=0; buy--){
                for(int tran=k; tran>0; tran--){
                    int profit = 0;
                    if(buy) profit = max(-prices[day]+next[0][tran], next[1][tran]);
                    else profit = max(prices[day]+ next[1][tran-1], next[0][tran]);
                    cur[buy][tran] = profit;
                }
            }
            next = cur;
        }
        return next[1][k];
    }
};