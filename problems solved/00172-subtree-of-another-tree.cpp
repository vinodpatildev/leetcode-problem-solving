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
    bool checkTreeEqual(TreeNode* root1, TreeNode* root2){
        if(!root1 || !root2){return root1 == root2;}
        if(root1->val != root2->val){return false;}
        return checkTreeEqual(root1->left,root2->left) && checkTreeEqual(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root ){return root==subRoot;}
        if(root->val == subRoot->val && checkTreeEqual(root,subRoot)){return true;}
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};