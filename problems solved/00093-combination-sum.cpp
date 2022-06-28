class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &d, int index, int target){
        if(target==0){
            ans.push_back(d);
            return;
        }
        if(index >= candidates.size() ||  target < 0){
            return;
        }
        
        helper(ans,candidates,d,index+1,target);
        
        d.push_back(candidates[index]);
        helper(ans,candidates,d,index,target-candidates[index]);
        d.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> d;
        
        helper(ans,candidates,d,0,target);
        return ans;
    }
};