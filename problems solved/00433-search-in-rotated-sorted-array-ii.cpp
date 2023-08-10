class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), rotation=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                rotation = i;
                break;
            }
        }
        cout<<"rotation :"<<rotation<<endl;
        int left = 0, right = n, mid;
        while(left<right){
            mid = (left+right)/2; 
            if(nums[(mid+rotation) % n] < target) left = mid+1;
            else right = mid;
        }
        
        return nums[(left+rotation) % n] == target ;
    }
};