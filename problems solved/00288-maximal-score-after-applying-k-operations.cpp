class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq;
        for(int it=0; it<nums.size(); it++) pq.push(nums[it]);
        for(int it=0; it<k; it++) {
            int topElement = pq.top(); pq.pop();
            score += topElement;
            if(topElement%3) topElement = topElement/3 + 1;
            else topElement = topElement/3;
            pq.push(topElement);
        }
        return score;
    }
};