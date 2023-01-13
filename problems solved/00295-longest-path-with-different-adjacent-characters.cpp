class Solution {
public:
    int dfs(int node,int& res,string &s, unordered_map<int,vector<int>>& graph, unordered_map<int,bool>& visited){
        if(visited[node]) return 0;
        visited[node] = true;

        //Children Work
        priority_queue <int> maxChildPathLengths;
        for(auto neighbor:graph[node]){
            if(!visited[neighbor] && s[node] != s[neighbor]){
                maxChildPathLengths.push(dfs(neighbor,res,s,graph,visited));
            }else{
                dfs(neighbor,res,s,graph,visited);
            }
        }
        int currResult=1;
        int maxUnrepeatedPathLength=0; 
        if(maxChildPathLengths.size()){
            maxUnrepeatedPathLength = maxChildPathLengths.top(); maxChildPathLengths.pop();
            currResult += maxUnrepeatedPathLength;
            if(maxChildPathLengths.size()) currResult += maxChildPathLengths.top();
        } 
        res = max(currResult,res);
        return maxUnrepeatedPathLength+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int res=0;
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> visited;
        graph[0] = vector<int>();
        for(int i=1; i<parent.size(); i++) graph[parent[i]].push_back(i);
        cout<<"graph size:"<<graph.size()<<endl;
        dfs(0,res,s,graph,visited);
        return res;
    }
};