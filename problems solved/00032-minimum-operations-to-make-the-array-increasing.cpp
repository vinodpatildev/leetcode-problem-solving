class Solution {
public:
    int minOperations(vector<int>& nums) {
        int prevHigh = nums[0];
        int sum = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=prevHigh){
                sum += (prevHigh-nums[i])+1;
                prevHigh++;
            }else{
                prevHigh = nums[i];
            }
        }
        return sum;
    }
};