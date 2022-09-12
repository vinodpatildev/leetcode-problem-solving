class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if(map[nums[i]+k]){count += map[nums[i]+k];}
            if(map[nums[i]-k]){count += map[nums[i]-k];}
            map[nums[i]]++;                
        }
        return count;
    }
};