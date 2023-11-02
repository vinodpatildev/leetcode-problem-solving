class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int num1=INT_MIN, num2=INT_MIN, count1=0, count2=0, size = nums.size();
        for(int i=0; i<size; i++){
            if(num1 == nums[i]) count1++;
            else if(num2 == nums[i]) count2++;
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int i=0; i<size; i++){
            if(nums[i] == num1) count1++;
            if(nums[i] == num2) count2++;
        }
        if(count1 > size/3) res.push_back(num1);
        if(count2 > size/3) res.push_back(num2);
        return res;
    }
};