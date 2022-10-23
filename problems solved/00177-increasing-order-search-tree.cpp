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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root){return NULL;}

        root->right = increasingBST(root->right);
        root->left = increasingBST(root->left);

        if(!root->left){return root;}
        TreeNode* node = root->left;
        while(node->right){node = node->right;}
        node->right = root;
        node = root->left;
        root->left = NULL;
        return node;
    }
};