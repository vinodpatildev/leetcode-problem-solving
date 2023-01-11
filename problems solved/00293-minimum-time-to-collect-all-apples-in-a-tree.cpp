class Solution {
public:
    unordered_map <int, vector<int>> graph;
    unordered_map <int, bool> visited;
    void genGraph(vector<vector<int>>& edges){
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    int dfs(int node,int cost, vector<bool>& hasApple){
        if(visited[node]) return 0;
        visited[node] = true;

        int localCost=0;
        for(auto neighbor:graph[node]){
            localCost += dfs(neighbor,2,hasApple);
        }
        if(localCost==0 && !hasApple[node]) return 0;
        return cost+localCost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        genGraph(edges);
        return dfs(0,0,hasApple);
    }
};