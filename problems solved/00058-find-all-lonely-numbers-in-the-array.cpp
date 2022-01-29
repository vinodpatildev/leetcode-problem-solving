class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        unordered_map <int,int> map;
        for(int i=0; i<size; i++){map[nums[i]]++;}
        for(auto e:map){if(e.second==1){
            if(map.find(e.first-1) == map.end() && map.find(e.first+1)==map.end()){
                ans.push_back(e.first);
            }
        }}
        return ans;
    }
};