class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res=0,sum=0;
        if(k>nums.size()) return res;
        
        unordered_set<int> st;
        unordered_map<int,int> map;
        
        for(int i=0; i<k-1; i++) sum += nums[i], st.insert(nums[i]), map[nums[i]]++;
        
        for(int i=k-1; i<nums.size(); i++){
            sum += nums[i];
            st.insert(nums[i]);
            map[nums[i]]++;
            
                        
            if(st.size() == k) res = max(res,sum);          
            
            if(map[nums[i-k+1]] == 1) st.erase(nums[i-k+1]);
            
            map[nums[i-k+1]]--;
            sum -= nums[i-k+1];
        }
        return res;
    }
};