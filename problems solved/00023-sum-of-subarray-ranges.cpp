class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int l,m;
        long long sum = 0;
        for(int i=0; i<n; i++){
            l = nums[i];
            m = nums[i];
            for(int j=i; j<n; j++){
                if(nums[j]<l){
                    l = nums[j];
                }
                if(nums[j]>m){
                    m = nums[j];
                }
                sum += (m-l);
            }
        }
        return sum;
    }
};