class Solution {
    void dfs(int node,vector<int> adj[],vector<bool>& vis){
        vis[node] = true;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,adj,vis);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> rest(n,false);
        vector<int> adj[n];
        vector<bool> vis(n,false);
        int count=0;
        for(auto node : restricted) rest[node] = true;
        for(auto edge : edges) {
            if(!rest[edge[0]] && !rest[edge[1]]){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
        }
        dfs(0,adj,vis);
        for(int node=0; node<n; node++){
            if(vis[node]) count++;
        }      
        return count;        
    }
};