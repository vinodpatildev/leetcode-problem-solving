class NumArray {
public:
    vector<long> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        long int r = prefixSum[right];
        long int l = (left>0)?prefixSum[left-1]:0;
        return r-l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */