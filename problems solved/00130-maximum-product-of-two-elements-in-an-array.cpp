
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int index;
        int num1 = 0;
        int num2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(num1<=nums[i]){
                num1 = nums[i];
                index = i;
            }
        }
        nums[index] = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(num2<=nums[i]){
                num2 = nums[i];
            }
        }
        
        return (num1-1)*(num2-1);
    }
};