class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left=0, right=nums.size()-1;
        while(left<=right){
            if(left==right){
                ans += nums[left];
            }
            else{
                long long l=nums[left], r=nums[right];
                long long rr = r;
                while(rr){
                    l *= 10;
                    rr /= 10;
                }
                l += r;
                ans += l;            
            }
            left++; right--;
        }
        return ans;
    }
};