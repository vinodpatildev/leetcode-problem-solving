class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        vector<int> prefixLeft(size); prefixLeft[0] = 1;
        vector<int> prefixRight(size); prefixRight[size-1] = 1;
        
        for(int i=1; i<size; i++){prefixLeft[i] = prefixLeft[i-1]*nums[i-1];}
        for(int i=size-2; i>=0; i--){prefixRight[i] = prefixRight[i+1]*nums[i+1];}
        
        for(int i=0; i<size; i++){ans.push_back(prefixLeft[i]*prefixRight[i]);}
        return ans;
    }
};