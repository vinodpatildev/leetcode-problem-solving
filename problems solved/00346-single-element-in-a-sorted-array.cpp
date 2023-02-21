class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto element : nums)  s.insert(element);
        for(auto element : s) {
            auto p = equal_range(nums.begin(),nums.end(),element);
            if(p.second - p.first == 1) return element;
        }
        return -1;
    }
};