class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void helper(vector<vector<int>> &ans, vector<int> &nums, int index ){
        if(index==nums.size()){
            ans.push_back(nums);
        }
        unordered_map <int,int> map;        
        for(int i=index; i<nums.size(); i++){
            if(map[nums[i]]){continue;}
            
            swap(nums[i],nums[index]);
            helper(ans,nums,index+1);
            swap(nums[i],nums[index]);
            
            map[nums[i]]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans,nums,0);
        return ans;
    }
};