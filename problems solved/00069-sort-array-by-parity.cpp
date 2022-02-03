class Solution {
public:
    void swap(int *a,int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size = nums.size(),j=-1,i;
        
        for(i=0; i<size; i++){
            if(nums[i]%2==0){swap(&nums[i],&nums[++j]);}
        }
        return nums;        
    }
};