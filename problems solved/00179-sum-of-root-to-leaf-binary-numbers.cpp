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
    int sumRootToLeaf(TreeNode* root, int number = 0) {
        if(!root){return 0;}
        number = number*2 + root->val;
        if(!root->left && !root->right){return number;}
        return sumRootToLeaf(root->left,number) + sumRootToLeaf(root->right,number);
    }
};