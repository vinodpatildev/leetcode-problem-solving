class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int u,d;
        u = d = 0;
        for(int i=prices.size()-1; i>=0; i--){
            d = max(-prices[i]+u, d);
            u = max(prices[i]+d, u);
        }
        return d;
    }
};