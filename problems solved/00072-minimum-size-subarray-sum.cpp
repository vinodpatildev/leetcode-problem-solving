class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size(),sum=0,len=INT_MAX,l=0,r=-1;
        while(r<size){
            if(sum<target){
                if(++r<size){sum += nums[r];}
            }else{
                len = min(len,r-l+1);
                if(l+1>r){return 1;}
                else{sum -= nums[l++];}
            }
        }
        return len!=INT_MAX?len:0;
    }
};