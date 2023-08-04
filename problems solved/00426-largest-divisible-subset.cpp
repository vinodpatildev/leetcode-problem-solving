class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> map(n,-1);

        int lds_ind = 0;
        for(int it=1; it<n; it++){
            for(int prev=0; prev<it; prev++){
                if(nums[it]%nums[prev] == 0 && dp[prev]+1 > dp[it]){
                    dp[it] = dp[prev] + 1;
                    map[it] = prev;
                }
            }
            if(dp[it] > dp[lds_ind]) lds_ind = it;
        }
        vector<int> res;
        while(lds_ind != -1){
            res.push_back(nums[lds_ind]);
            lds_ind = map[lds_ind];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};