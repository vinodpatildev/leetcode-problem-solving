class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        int topo = 0;
        queue<int> todo;
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        for(int node=0; node<numCourses; node++){
            if(indeg[node]==0) todo.push(node);
        }
        while(!todo.empty()){
            int node = todo.front(); todo.pop(); topo++;
            for(int neighbor : adj[node]){
                if((--indeg[neighbor]) == 0) todo.push(neighbor);
            }
        }
        return topo == numCourses;
    }
};