class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int arr_size = nums.size();
        int i = -1;
        int temp;
          for(int j=0; j< arr_size; j++){
              if(nums[j] != val){
                  temp = nums[++i];
                  nums[i] = nums[j];
                  nums[j] = temp;                
              }
          }
        return ++i;
    }
};