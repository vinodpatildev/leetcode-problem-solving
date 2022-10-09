/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if(!root){return maxWidth;}
        queue<pair<TreeNode*,__int128>> todo;
        todo.push({root,0});
        while(!todo.empty()){
            int size = todo.size();
            __int128 mmin = todo.front().second;
            __int128 first = todo.front().second - mmin;
            __int128 last = todo.back().second - mmin;
            int width = last - first + 1;
            maxWidth = max(maxWidth , width);
            for(int i=0; i<size; i++){
                auto node_pair = todo.front(); todo.pop();
                TreeNode* node = node_pair.first;
                __int128 node_index = node_pair.second - mmin;
                if(node->left){todo.push({node->left, 2*node_index+1});}
                if(node->right){todo.push({node->right, 2*node_index+2});}           
            }
        }
       return maxWidth;
    }
};