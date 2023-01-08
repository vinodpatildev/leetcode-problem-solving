class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0,neg=0;
        for(int it=0; it<nums.size(); it++) {
            if(nums[it]>0) pos++;
            else if(nums[it]<0) neg++;
        }
        return max(pos,neg);
    }
};