class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<int> avgDiff(nums.size());
        long long int leftSum = 0, rightSum = 0;
        for(int i=0; i<nums.size(); i++) rightSum += nums[i];
        for(int i=0; i<nums.size(); i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            avgDiff[i] = i<nums.size()-1 ? (leftSum/(i+1))-(rightSum/(nums.size()-i-1)) : (leftSum/(i+1));
            avgDiff[i] = abs(avgDiff[i]);
        }
        int resIndex = 0;
        for(int i=0; i<avgDiff.size(); i++) if(avgDiff[i] < avgDiff[resIndex]) resIndex = i;
        return resIndex;
    }
};