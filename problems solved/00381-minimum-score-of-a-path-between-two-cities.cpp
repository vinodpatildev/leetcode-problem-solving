class Solution {
    void dfs(int node,int& res, vector<pair<int,int>> adj[], vector<bool>& vis){
        if(vis[node]) return;
        vis[node] = true;
        for(auto adjNodePair : adj[node]){
            int adjNode = adjNodePair.first;
            int adjScore = adjNodePair.second;
            res = min(res,adjScore);
            dfs(adjNode,res,adj,vis);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int res = 1e9;
        vector<pair<int,int>> adj[n+1];
        vector<bool> vis(n+1,false);
        vis[0] = true;
        for(auto road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        dfs(1,res,adj,vis);
        return res;
    }
};