class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> adj[n];
        for(int node=0; node<n; node++){
            for(int adjacentNode : graph[node]) {
                adj[adjacentNode].push_back(node);
            }
        }
        vector<int> indeg(n,0);
        queue<int> todo_queue;
        vector<int> topo;
        
        for(int node=0; node<n; node++){
            for(auto adjacentNode : adj[node]) {
                indeg[adjacentNode]++;
            }
        }
        for(int node=0; node<n; node++){
            if(indeg[node] == 0) todo_queue.push(node);
        }
        while(!todo_queue.empty()){
            int node = todo_queue.front(); todo_queue.pop();
            topo.push_back(node);
            
            for(auto adjacentNode : adj[node]) {
                if((--indeg[adjacentNode]) == 0 ) todo_queue.push(adjacentNode);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};