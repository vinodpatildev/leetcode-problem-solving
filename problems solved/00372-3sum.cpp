class  Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int it=0; it<nums.size()-2; it++){
            if(it>0 && nums[it] == nums[it-1]) continue;
            int left = it+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[it] + nums[left] + nums[right];
                if(sum == 0){
                    res.push_back({nums[it],nums[left],nums[right]});
                    while(left+1<nums.size() && nums[left] == nums[left+1])left++;
                    while(right-1>=0 && nums[right-1] == nums[right]) right--;
                    left++;
                    right--;
                }else if(sum < 0) left++;
                else right--; 
            }
        }
        return res; 
    }
};

// -4 -1 -1 0 1 2