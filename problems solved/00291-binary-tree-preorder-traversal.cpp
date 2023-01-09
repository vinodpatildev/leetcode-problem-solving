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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(!root) return pre;
        stack<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            TreeNode* curr = todo.top(); todo.pop();
            pre.push_back(curr->val);
            if(curr->right) todo.push(curr->right);
            if(curr->left) todo.push(curr->left);
        }
        return pre;
    }
};