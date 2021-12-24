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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        
        int minHeight ;
        
        if(leftHeight&&rightHeight){
            minHeight = min(leftHeight,rightHeight);
        }else if(leftHeight==0){
            minHeight = rightHeight;
        }else if(rightHeight==0){
            minHeight = leftHeight;
        }
        
        return minHeight+1;
    }
};