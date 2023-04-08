/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map <Node*, Node*> nodemap;
    void dfs(Node* node){
        if(node == NULL || nodemap.find(node) != nodemap.end()) return;
        nodemap[node] = new Node(node->val,node->neighbors);
        for(auto adjNode : node->neighbors){
            dfs(adjNode);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        dfs(node);
        for(auto p : nodemap){
            int size = p.second->neighbors.size();
            for(int it=0; it<size; it++) p.second->neighbors[it] = nodemap[p.second->neighbors[it]];
        }
        Node* res = nodemap[node];
        nodemap.clear();
        return res;
    }
};