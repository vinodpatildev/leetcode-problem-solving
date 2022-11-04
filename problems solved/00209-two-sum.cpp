class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map <int,int> mpp;

        for(int i=0; i<nums.size(); i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                res.emplace_back(mpp[target-nums[i]]);
                res.emplace_back(i);
                break;
            }
            mpp[nums[i]] = i;
        }
        return res;
    }
};