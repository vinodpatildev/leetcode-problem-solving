class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int num_size = nums.size();
        vector<int> ans;
        priority_queue <pair<int,int>> pq1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        
        for(int i=0; i<num_size; i++){
            pq1.push(make_pair(nums[i],i));
        }
        while(k--){
            pair<int,int> p;
            p = pq1.top();
            pq1.pop();
            pq2.push(make_pair(p.second,p.first));
        }
        while(!pq2.empty()){
            pair<int,int> p;
            p = pq2.top();
            pq2.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};