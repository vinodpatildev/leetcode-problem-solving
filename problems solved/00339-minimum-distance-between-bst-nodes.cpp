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
    void dfs(TreeNode* root, int& ans){
        if(root == NULL) return;
        if(root->left) {
            int value = 0;
            TreeNode* node = root->left;
            while(node){
                value = node->val;
                node = node->right;
            }
            ans = min(ans, root->val - value);
        }
        if(root->right) {
            int value = 0;
            TreeNode* node = root->right;
            while(node){
                value = node->val;
                node = node->left;
            }
            ans = min(ans, value - root->val);
        }

        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        dfs(root,ans);
        return ans;
    }
};