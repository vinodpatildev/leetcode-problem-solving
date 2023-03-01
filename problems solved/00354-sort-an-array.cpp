class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> arr;
        for(int element : nums) arr.push_back(element);
        sort(arr.begin(),arr.end());
        return arr;
    }
};