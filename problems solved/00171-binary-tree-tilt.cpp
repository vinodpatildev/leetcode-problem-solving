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
    int computeTilt(TreeNode* root,int& tilt){
        if(!root){return 0;}
        int leftTilt = computeTilt(root->left,tilt);
        int rightTilt = computeTilt(root->right,tilt);
        tilt += abs(leftTilt - rightTilt);
        return root->val + leftTilt + rightTilt;
    }
    int findTilt(TreeNode* root) {
        if(!root){return 0;}
        int tilt = 0;
        computeTilt(root,tilt);
        return tilt;
    }
};