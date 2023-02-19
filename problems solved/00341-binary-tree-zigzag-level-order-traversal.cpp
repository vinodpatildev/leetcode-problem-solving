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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> todo;
        todo.push(root);
        int l = 0;

        while(!todo.empty()){
            int size = todo.size();
            vector<int> level;
            for(int it=0; it<size; it++){
                TreeNode* node = todo.front(); todo.pop();
                if(node == NULL) continue;
                level.push_back(node->val);
                if(node->left) todo.push(node->left);
                if(node->right) todo.push(node->right);
            }
            if(l&1) reverse(level.begin(), level.end());
            res.push_back(level);
            l++;
        }
        return res;
    }
};