class Solution {
    int fun(const vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi=INT_MIN;
        for(int it=i; it<=j; it++){
            int points = nums[i-1] * nums[it] * nums[j+1]
                + fun(nums,i,it-1,dp) 
                + fun(nums,it+1,j,dp);
            maxi = max(maxi,points); 
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return fun(nums,1,n,dp);
    }
};