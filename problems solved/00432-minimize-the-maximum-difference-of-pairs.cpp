class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int mid, count, n = nums.size(), left=0, right=nums[n-1]-nums[0];

        while(left<right){
            mid = (left+right)/2;
            count=0;

            for(int it=1; it<n; it++){
                if(nums[it]-nums[it-1] <= mid){
                    count++;
                    it++;
                }
            }

            if(count >= p) right=mid;
            else left=mid+1;
        }
        return left;
    }
};