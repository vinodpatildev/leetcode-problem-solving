class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> map;
        int count = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if(i>0 && nums[i]==nums[i-1]){map[nums[i]]++;continue;}
            if(map[nums[i]+k]){count++;}        
            map[nums[i]]++;
        }
        return count;
    }
};