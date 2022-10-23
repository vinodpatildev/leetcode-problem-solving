class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){ ans[0] = abs(nums[i]); }
            else{ nums[index] = - nums[index]; } 
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0){ ans[1] = i+1; }
        }
        return ans;
    }
};