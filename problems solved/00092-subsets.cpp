class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &nums,vector<int> &instance_set, int index){
        ans.push_back(instance_set);
        
        for(int i=index; i<nums.size(); i++){
            instance_set.push_back(nums[i]);
            helper(ans,nums,instance_set,i+1);
            instance_set.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> instance_set;
        
        helper(ans,nums,instance_set,0);
        return ans;
    }
};