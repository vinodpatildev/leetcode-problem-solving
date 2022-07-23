class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int index = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                swap(nums[++index], nums[i]);
            }
        }
        for(int i=index+1; i<nums.size(); i++){
            if(nums[i]==1){
                swap(nums[++index], nums[i]);
            }
        }        
    }
};