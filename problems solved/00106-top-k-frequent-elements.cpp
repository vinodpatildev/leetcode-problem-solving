class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto e:map){
            pq.push(make_pair(e.second,e.first));
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};