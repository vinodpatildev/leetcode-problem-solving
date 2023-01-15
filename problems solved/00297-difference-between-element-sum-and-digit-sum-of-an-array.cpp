class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        long elementSum=0;
        long digitSum=0;
        
        int element;
        for(int it=0; it<nums.size(); it++){
            element = nums[it];
            elementSum += element;
            while(element){
                digitSum += element%10;
                element = element/10;
            }
        }
        return abs(elementSum-digitSum);
    }
};