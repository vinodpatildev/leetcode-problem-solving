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
    void helper(TreeNode* node,vector<int> &level,int l){
        if(node==NULL){return;}
        if(level.size()==l){
            level.push_back(node->val);
        }
        if(l<level.size()){
            level[l] = max(level[l],node->val);
        }
        helper(node->left,level,l+1);
        helper(node->right,level,l+1);        
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> level;
        helper(root,level,0);
        return level;
    }
};