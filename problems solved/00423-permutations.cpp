class Solution {
    void gen(int start,vector<int>& nums,vector<vector<int>>& res){
        if(start == nums.size()-1){
            res.push_back(nums);
            return;
        }

        for(int it=start; it<nums.size(); it++){
            swap(nums[it],nums[start]);
            gen(start+1,nums,res);
            swap(nums[it],nums[start]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        gen(0,nums,res);
        return res;
    }
};