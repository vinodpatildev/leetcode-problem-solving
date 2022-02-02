class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size(),start=-1,end=-1,count=0;
        
        for(int i=0; i<size; i++){
            if(nums[i]>=left&&nums[i]<=right){
                end = i;
                count += end-start;
            }else if(nums[i]>right){
                start=end=i;
            }else{
                count += end-start;
            }
        }
        return count;
    }
};