class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size==0){return;}
        k = k%size;
        if(k==0){return;}
        vector<int> temp(k);
        for(int i=0; i<k; i++){
            temp[i] = nums[size-k+i];
        }
        for(int i=size-k-1; i>=0; i--){
            nums[i+k] = nums[i];
        }
        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }
    }
};