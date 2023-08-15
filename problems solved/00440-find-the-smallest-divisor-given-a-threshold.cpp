class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int n = nums.size();
        int smallestDivisor = 1;
        int largestDivisor = *max_element(nums.begin(),nums.end());


        while(smallestDivisor <= largestDivisor){
            int midDivisor = (smallestDivisor + largestDivisor)/2;


            int sumDivisions = 0;
            for(int it=0; it<n; it++) sumDivisions += ((nums[it]-1)/midDivisor) + 1;

            if(sumDivisions <= threshold){
                ans = midDivisor;
                largestDivisor = midDivisor-1;
            }
            else smallestDivisor = midDivisor+1;
        }
        return ans;
    }
};


