class Solution {
public:
    void rec(set<vector<int>>& res,vector<int>& nums,vector<int>& lis, int index){
        if(index==nums.size()) {
            if(lis.size()>1) res.insert(lis);
            return;
        }
        rec(res,nums,lis,index+1);
        if(lis.size()==0 || lis[lis.size()-1]<=nums[index]){
            lis.push_back(nums[index]);
            rec(res,nums,lis,index+1);
            lis.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ans;
        if(nums.size()<=1) return ans;
        vector<int> lis;
        rec(res,nums,lis,0);
        for(auto lis:res) ans.push_back(lis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};