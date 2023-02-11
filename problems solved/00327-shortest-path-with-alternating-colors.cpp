class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int level = 0;
        vector<int> redAdj[n];
        vector<int> blueAdj[n];
        for(auto edge : redEdges){
            redAdj[edge[0]].push_back(edge[1]);
        }
        for(auto edge : blueEdges){
            blueAdj[edge[0]].push_back(edge[1]);
        }
        queue<pair<int,int>> todo;
        vector<int> red_visited(n,0);
        vector<int> blue_visited(n,0);
        vector<int> ans(n,-1);

        todo.push({0,-1});
        
        while(!todo.empty()){
            int level_count = todo.size();
            for(int it=0; it<level_count; it++){
                pair<int,int> node_pair = todo.front(); todo.pop();
                if(ans[node_pair.first] == -1) ans[node_pair.first] = level;
                if(node_pair.second == 1 || node_pair.second == -1){
                    for(auto neighbour : redAdj[node_pair.first]){
                        if(red_visited[neighbour]==0){
                            red_visited[neighbour] = 1;
                            todo.push({neighbour,0});
                        }
                    }
                }
                if(node_pair.second == 0 || node_pair.second == -1){
                    for(auto neighbour : blueAdj[node_pair.first]){
                        if(blue_visited[neighbour]==0){
                            blue_visited[neighbour] = 1;
                            todo.push({neighbour,1});
                        }
                    }
                }
            }
            level++;
        }
        return ans;
    }
};