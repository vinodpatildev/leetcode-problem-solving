class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int k1 = INT_MAX, k2 = INT_MAX;
        for(int element : nums){
            if(element <= k1) k1 = element;
            else if(element <= k2) k2 = element;
            else return true;
        }
        return false;
    }
};