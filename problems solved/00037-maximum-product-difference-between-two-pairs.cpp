class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max = nums[nums.size()-1];
        int secondMax = nums[nums.size()-2];
        int min = nums[0];
        int secondMin = nums[1];
        
        return (max*secondMax)-(min*secondMin);
    }
};