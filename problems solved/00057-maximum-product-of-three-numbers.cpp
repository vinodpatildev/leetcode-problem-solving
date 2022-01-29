class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[0]*nums[1]*nums[size-1];
        int b = nums[size-1]*nums[size-2]*nums[size-3];
        
        return max(a,b);
    }
};