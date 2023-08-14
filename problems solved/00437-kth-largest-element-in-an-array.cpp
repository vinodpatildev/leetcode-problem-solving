class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int it=0; it<nums.size(); it++){
            pq.push(nums[it]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
