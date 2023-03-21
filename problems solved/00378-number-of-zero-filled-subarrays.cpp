class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;
        for(int it=0; it<=nums.size(); it++){
            if(it == nums.size() || nums[it] != 0){
                if(count > 0){
                    
                    ans += count*(count+1)/2;
                    count = 0;
                }
            }else count++;
        }
        return ans;
    }
};
