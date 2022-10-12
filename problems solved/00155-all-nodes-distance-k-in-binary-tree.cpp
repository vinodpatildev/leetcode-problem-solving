/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(!root){return res;}
        unordered_map<TreeNode*,TreeNode*> mpp;
        queue<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            TreeNode* curr = todo.front(); todo.pop();
            if(curr->left){
                mpp[curr->left]=curr;
                todo.push(curr->left);
            }
            if(curr->right){
                mpp[curr->right]=curr;
                todo.push(curr->right);
            }
        }
        unordered_map<TreeNode*,int> visited;
        queue<TreeNode*> nodes;
        nodes.push(target);
        while(!nodes.empty()){
            int size = nodes.size();
            for(int i=0; i<size; i++){
                TreeNode* node = nodes.front(); nodes.pop();
                if(k==0){
                    res.push_back(node->val);
                }else if(k>0){
                    if(node->left && !visited[node->left]){
                        nodes.push(node->left);
                    }
                    if(node->right && !visited[node->right]){
                        nodes.push(node->right);
                    }
                    if(mpp[node] && !visited[mpp[node]]){
                        nodes.push(mpp[node]);
                    }
                }
                visited[node]++;
            }
            k--;
        }
        return res;
    }
};