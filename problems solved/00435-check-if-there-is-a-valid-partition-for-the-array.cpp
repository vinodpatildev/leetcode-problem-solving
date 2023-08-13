class Solution {
    bool fun(const vector<int>& nums, int i,vector<int>& dp){
        int n=nums.size();
        if(i>=n) return true;

        if(dp[i] != -1) return dp[i];

        int ans = false;
        if(i+1<n && nums[i] == nums[i+1]){
            if(fun(nums,i+2,dp)) ans = true;
            else if(i+2<n && nums[i+1] == nums[i+2]) ans = fun(nums,i+3,dp);
        } else if(i+2<n && nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]) ans = fun(nums,i+3,dp);

        return dp[i] = ans;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(nums,0,dp);
    }
};