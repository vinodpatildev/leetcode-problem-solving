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
    int totalNodes(TreeNode* root){
        if(root == NULL) return 0;
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
    bool isComplete(TreeNode* root, int total, int index){
        if(root == NULL) return true;
        if(index >= total) return false;
        return isComplete(root->left,total,2*index+1) && isComplete(root->right,total,2*index+2);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int total = totalNodes(root);
        return isComplete(root,total,0);
    }
};