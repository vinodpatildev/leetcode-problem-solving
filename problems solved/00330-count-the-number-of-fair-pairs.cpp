class Solution {
public:
    int lowerIndex(vector<int>& arr, int size, int x)
    {
        int l = 0, h = size - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr[mid] >= x)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    int upperIndex(vector<int>& arr, int size, int y)
    {
        int l = 0, h = size - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr[mid] <= y)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return h;
    }
 
    int countInRange(vector<int>& arr, int size, int index, int x, int y)
    {
        int count = 0;
        if(x>y) return count;
        count = upperIndex(arr, size, y) - max(index+1,lowerIndex(arr, size, x)) + 1;
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        for(int it=0; it<size-1; it++){
            int new_lower = max(lower-nums[it],nums[it]);
            int new_upper = upper-nums[it];
            ans += countInRange(nums,size,it,new_lower,new_upper);            
        }
        
        return ans;
    }
};