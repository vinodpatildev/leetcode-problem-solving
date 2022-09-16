class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();  
        int diff = n-m;
        
        vector<int> dp(m);
        
        for(int gap = 0; gap < m; gap++) {
            
            vector<int> current(m);
            
            for(int i=0 , j=gap ;  j < n - diff ; i++ ,j++) { 
                           
                current[j] = max((gap == 0 ? 0 : dp[j]) + nums[i]*multipliers[m-1-gap], // from front
                                 (gap == 0 ? 0 : dp[j-1]) + nums[j+diff]*multipliers[m-1-gap]); // from back
            }
            
            dp = current;
        }
        return dp[m-1];
    }
};