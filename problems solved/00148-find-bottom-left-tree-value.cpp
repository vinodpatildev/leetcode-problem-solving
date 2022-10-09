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
    void leftViewHelper(TreeNode* root, vector<int>& leftView, int level){
        if(root==NULL){return;}
        if(level==leftView.size()){leftView.push_back(root->val);}
        leftViewHelper(root->left,leftView,level+1);
        leftViewHelper(root->right,leftView,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> leftView;
        leftViewHelper(root,leftView,0);
        return leftView[leftView.size()-1];
    }
};