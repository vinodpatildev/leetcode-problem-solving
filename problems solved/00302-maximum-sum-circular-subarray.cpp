class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res,rightMax,n=nums.size(),suff;
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int it=1; it<n; it++){
            if(pre[it-1]>0) pre[it] += pre[it-1];
            pre[it] += nums[it];
        }
        res = *max_element(pre.begin(),pre.end());
        for(int it=1; it<n; it++) pre[it] = pre[it-1] + nums[it];
        rightMax = nums[n-1];
        suff = nums[n-1];
        for(int it=n-2; it>=0; it--){
            res = max(res,pre[it]+rightMax);
            suff += nums[it];
            rightMax = max(rightMax,suff);
        }
        return res;
    }
};