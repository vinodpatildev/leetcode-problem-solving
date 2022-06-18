class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> mask(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            mask[nums[i]]++;
        }
        for(int i=0; i<mask.size(); i++){
            if(mask[i]>1){
                return i;
            }
        }
        return -1;
    }
};