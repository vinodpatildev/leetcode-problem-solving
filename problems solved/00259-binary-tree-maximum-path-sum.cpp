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
    int helper(TreeNode* root,int& maxPathSum){
        if(root==NULL){return 0;}
        int ls = max(0,helper(root->left,maxPathSum));
        int rs = max(0,helper(root->right,maxPathSum));
        maxPathSum = max(maxPathSum, ls+rs+root->val);
        return max(ls,rs)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        helper(root,maxPathSum);
        return maxPathSum;
    }
};