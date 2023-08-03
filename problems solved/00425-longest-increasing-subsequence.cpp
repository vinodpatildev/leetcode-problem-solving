class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int it=1; it<nums.size(); it++){
            int left = 0, right = lis.size();
            while(left < right){
                int mid = (left+right)/2;
                if(lis[mid] < nums[it]) left = mid+1;
                else right = mid;
            }
            if(left == lis.size()) lis.push_back(nums[it]);
            else lis[left] = nums[it];
        }
        return lis.size();
    }
};