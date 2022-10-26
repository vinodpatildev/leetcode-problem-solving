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
    int build(TreeNode* root,int greaterSum){
        if(!root){return 0;}
        int rightSum = build(root->right,greaterSum);
        root->val = root->val + rightSum + greaterSum;
        int leftSum = build(root->left,root->val);
        return root->val + leftSum  - greaterSum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root){return NULL;}
        build(root,0);
        return root;
    }
};