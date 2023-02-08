class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0,right=min(nums[0], (int)nums.size()-1), ans=1;
        if(right==0) return 0;
        int maxHopJump = 0;
        while(left<=right){
            maxHopJump = max(maxHopJump, left + nums[left]);
            if(left==right) {
                if(left==nums.size()-1) break;
                ans++;
                right = min(maxHopJump, (int)nums.size()-1);
                maxHopJump=0;
            }
            left++;
        }
        return ans;
    }
};