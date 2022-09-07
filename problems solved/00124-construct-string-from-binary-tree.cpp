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
    string tree2str(TreeNode* root) {
        if(root==NULL){return "";}       
        
        string ans = "";
        string left_str = tree2str(root->left);
        string right_str = tree2str(root->right);
        
        if(!right_str.empty()){
            ans = ans + "("+right_str+")";
            ans = "("+left_str+")"+ans;            
        }else if(!left_str.empty()){
            ans = "("+left_str+")" + ans;
        }
        ans = to_string(root->val) + ans;
        
        return ans;
    }
};