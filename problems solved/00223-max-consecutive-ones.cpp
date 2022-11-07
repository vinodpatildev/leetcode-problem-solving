class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> arr = nums;
        for(int i=1; i<arr.size(); i++) if(arr[i]>0) arr[i] += arr[i-1];
        return *max_element(arr.begin(),arr.end());
    }
};