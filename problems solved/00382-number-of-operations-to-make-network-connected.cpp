class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& vis){
        vis[node] = true;
        for(int adjNode : adj[node]){
            if(!vis[adjNode]) dfs(adjNode,adj,vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size() < n - 1) return -1;
        vector<int> adj[n];
        for(int it=0; it<conn.size(); it++){
            adj[conn[it][0]].push_back(conn[it][1]);
            adj[conn[it][1]].push_back(conn[it][0]);
        }
        vector<bool> vis(n,false);
        int components = 0;
        for(int node=0; node<n; node++) {
            if(!vis[node]) {
                dfs(node,adj,vis);
                components++;
            }
        }
        return components-1;
    }
};