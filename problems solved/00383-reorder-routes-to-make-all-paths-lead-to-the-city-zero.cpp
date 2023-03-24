class Solution {
    int dfs(int node,vector<int> adj[], vector<bool>& vis){
        int rev = 0;
        vis[node] = true;
        for(int adjNode : adj[node]){
            if(!vis[abs(adjNode)]){
                if(adjNode > 0) rev++;
                rev += dfs(abs(adjNode),adj,vis);
            }
        }
        return rev;
    }
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<int> adj[n];
        for(auto edge : conn){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(-edge[0]);
        }
        vector<bool> vis(n,false);
        return dfs(0,adj,vis);
    }
};