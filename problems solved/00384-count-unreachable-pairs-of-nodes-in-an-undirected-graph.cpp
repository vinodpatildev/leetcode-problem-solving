class Solution {
    int dfs(int node, vector<int> adj[],vector<bool>& vis){
        int childCount = 0;
        vis[node] = true;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                childCount += dfs(adjNode,adj,vis);
            }
        }
        return childCount+1;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> components;
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        for(int node=0; node<n; node++){
            if(!vis[node]) components.push_back(dfs(node,adj,vis));
        }
        long long sum = 0, ans = 0;
        for(auto component : components) sum += component;
        for(auto component : components) {
            sum -= component;
            ans += component*(sum);
        }
        return ans;
    }
};