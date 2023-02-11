class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        bool allVisited = false;
        int nodes = isConnected.size();
        vector<int> visited(nodes,0);
        queue<int> todo;

        visited[0] = 1;
        todo.push(0);

        while(!allVisited){
            provinces++;
            while(!todo.empty()){
                int node = todo.front(); todo.pop();
                for(int it=0; it<nodes; it++){
                    if(isConnected[node][it] == 1 && !visited[it]){
                        visited[it] = 1;
                        todo.push(it);
                    }
                }
            }
            allVisited = true;
            for(int it=0; it<nodes; it++){
                if(visited[it] == 0){
                    allVisited = false;
                    visited[it] = 1;
                    todo.push(it);
                    break;
                }
            }
        }
        return provinces;
    }
};