class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int s = prices[0];
        int ans = INT_MIN,bp;
        for(int it=0; it<n; it++) {
            if(s<=prices[it]) bp = s;
            else s = bp = prices[it];
            ans = max(ans,prices[it]-bp);
        }
        return ans;
    }
};