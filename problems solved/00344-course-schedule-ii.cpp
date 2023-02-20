class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        vector<int> topo;
        queue<int> todo;
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        for(int node=0; node<numCourses; node++){
            if(indeg[node]==0) todo.push(node);
        }
        while(!todo.empty()){
            int node = todo.front(); todo.pop(); 
            topo.push_back(node);
            for(int neighbor : adj[node]){
                if((--indeg[neighbor]) == 0) todo.push(neighbor);
            }
        }
        if(topo.size() != numCourses) return {};
        return topo;
    }
};