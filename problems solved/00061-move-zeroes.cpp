class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(),temp;
        for(int i=1; i<size; i++){
            if(nums[i] != 0 && i>0 && nums[i-1]==0){
                temp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = temp;
                i=i-2;
            }
        }
    }
};