class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest=0;
        for(int i=0; i<nums.size(); i++){if(nums[i]>nums[largest]){largest=i;}}
        int target = nums[largest];
        nums[largest] /= 2;
        for(int i=0; i<nums.size(); i++){if(2*nums[i]>target){return -1;}}
        return largest;
    }
};