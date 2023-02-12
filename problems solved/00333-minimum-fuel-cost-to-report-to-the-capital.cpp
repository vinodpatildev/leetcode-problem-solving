class Solution {
public:
    pair<int,int> dfs(int node, int fuel, int seats, vector<int> adj[], vector<int>& cars, vector<bool>& visited){
        visited[node] = true;
        pair<int,int> res = {0,1};
        for(int child : adj[node]){
            if(visited[child]) continue;
            pair<int,int> childRes = dfs(child,fuel+1,seats,adj,cars,visited);
            res.first += childRes.first;
            res.second += childRes.second;
        }
        int need = res.second/seats;
        if(res.second%seats)  need++;

        if(res.first < need){
            res.first++;
            cars.push_back(fuel);
        }else if(res.first > need){
            cars.push_back(-(res.first-need)*fuel);
            res.first = need;

        }
        return res;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        int n = roads.size()+1;
        vector<int> adj[n];
        for(auto road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        vector<bool> visited(n,false);
        vector<int> cars;
        dfs(0,0,seats,adj,cars,visited);
        for(int fuel: cars) ans += fuel;
        return ans;
    }
};