class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int r = min_element(nums.begin(),nums.end()) - nums.begin();

        int left = 0, right = nums.size();
        while(left<right){
            int mid = (left+right)/2;
            if(nums[(mid+r)%n] < target) left = mid+1;
            else right = mid;
        }
        if(nums[(left+r)%n] != target) return -1;
        return (left+r)%n;
    }
};