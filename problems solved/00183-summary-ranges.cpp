class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0;
        for(int right=1; right<=nums.size(); right++){
            if(right == nums.size() || nums[right-1]+1 != nums[right]){
                string range = "";
                if(left+1 == right){
                    range += to_string(nums[left]);
                }else{
                    range += to_string(nums[left]);
                    range += "->";
                    range += to_string(nums[right-1]);
                }
                res.push_back(range);
                left = right;
            }
        }
        return res;
    }
};
