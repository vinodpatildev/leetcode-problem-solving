class Solution {
public:
    int binSearch(vector<int>& nums,int left,int right,int target){
        if(left>right){return -1;}
        int mid = left + (right-left)/2;
        if(nums[mid]==target){return mid;}
        else if(nums[mid]<target){ return binSearch(nums,mid+1,right,target); }
        else{ return binSearch(nums,left,mid-1,target); }
        
    }
    int search(vector<int>& nums, int target) {
        return binSearch(nums,0,nums.size()-1,target);
    }
};