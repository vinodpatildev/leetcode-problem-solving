class Solution {
    int fun(int i, int k, int n, vector<int>& arr, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxSum = 0;
        int maxi = 0;
        for(int it=i; it<min(i+k,n); it++){
            maxi = max(maxi,arr[it]);
            maxSum = max(maxSum, maxi*(it-i+1) + fun(it+1,k,n,arr,dp));
        }
        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(),maxSum,maxi,i,it;
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(i=n-1; i>=0; i--){
            maxSum = 0;
            maxi = 0;            
            for(it=i; it<min(i+k,n); it++){
                maxi = max(maxi,arr[it]);
                maxSum = max(maxSum, maxi*(it-i+1) + dp[it+1]);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }
};