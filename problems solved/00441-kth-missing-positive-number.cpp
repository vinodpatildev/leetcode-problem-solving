class Solution {
public:
    int findKthPositive(const vector<int>& nums, const int k) {
        int n = nums.size();
        int low=0, high=n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int numsMissing = nums[mid]-mid-1;
            if(numsMissing < k) low = mid+1;
            else high = mid-1;
        }
        return k + low;
    }
};


// int numsMissing = nums[high]-high-1
// ans = nums[high] + k - numsMissing
// ans = nums[high] + k - nums[high] + high + 1
// ans = k + high + 1 
//     == k + low


