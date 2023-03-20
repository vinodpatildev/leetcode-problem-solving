class NumArray {
    vector<int> num;
    vector<int> bit;
    int getSum(int index){
        index = index+1;
        int sum = 0;
        while(index > 0){
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }
    void add(int index, int val) {
        index = index + 1;
        while(index < bit.size()){
            bit[index] += val;
            index += index & (-index);
        }
    }
public:
    NumArray(vector<int>& nums) {
        num = nums;
        bit.resize(nums.size()+1,0);
        for(int it=0; it<nums.size(); it++) add(it,nums[it]);
    }
    
    void update(int index, int val) {
        add(index,val-num[index]);
        num[index] = val;
    }

    int sumRange(int left, int right) {
        return getSum(right) - getSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */