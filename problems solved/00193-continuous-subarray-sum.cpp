
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]%k;
            if(i>0){
                nums[i] = (nums[i] + nums[i-1])%k;
                if(nums[i]==0 || (mpp.find(nums[i]) != mpp.end() && mpp[nums[i]] != i-1)){
                    return true;
                }
            }
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]] = i;
            }
        }
        return false;
    }
};