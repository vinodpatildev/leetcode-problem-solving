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
    bool checkBST(TreeNode* root, long int leftRange, long int rightRange){
        if(!root){return true;}
        if(root->val<=leftRange || root->val>=rightRange){return false;}
        return checkBST(root->left,leftRange,root->val) && checkBST(root->right,root->val,rightRange);
    }
    bool isValidBST(TreeNode* root) {
        long int leftRange = LONG_MIN;
        long int rightRange = LONG_MAX;
        return checkBST(root,leftRange,rightRange);
    }
};