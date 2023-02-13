class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map <int,int> map;
        for(auto edge : edges){
            map[edge[0]]++;
            map[edge[1]]++;
        }
        int node, node_freq=INT_MIN;
        for(auto p : map){
            if(p.second > node_freq){
                node = p.first;
                node_freq = p.second;
            }
        }
        return node;
    }
};