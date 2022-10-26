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
    pair<int,int> helper(TreeNode* root,int& counter){
        if(!root){return {0,0};}
        pair<int,int> leftRes = helper(root->left,counter);
        pair<int,int> rightRes = helper(root->right,counter);
        int sum = leftRes.second + rightRes.second + root->val;
        int nodes = leftRes.first + rightRes.first + 1;
        if((sum/nodes) == root->val){counter++;}
        return {nodes,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        int counter=0;
        helper(root,counter);
        return counter;
    }
};