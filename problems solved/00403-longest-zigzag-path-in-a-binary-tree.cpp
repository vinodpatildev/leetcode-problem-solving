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
    int ans = 0;
public:
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> resl = solve(root->left);
        pair<int,int> resr = solve(root->right);       
        pair<int,int> res = {0,0};
        if( root->left ) res.first = resl.second+1;
        if( root->right ) res.second = resr.first+1;
        ans = max(ans,max(res.first,res.second));
        return res;
    }
    int longestZigZag(TreeNode* root) {
        ans = 0;
         solve(root);
         return ans;
    }
};