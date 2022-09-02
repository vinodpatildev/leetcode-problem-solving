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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> *st = new queue<TreeNode*>();
        queue<TreeNode*> *stt = new queue<TreeNode*>();
        vector<vector<int>> ans;
        vector<int> level;
        
        if(root){
            st->push(root);
        }
        
        while(!st->empty()){
            TreeNode* node = st->front();
            st->pop();
            level.push_back(node->val);
            
            if(node->left){
                stt->push(node->left);
            }
            if(node->right){
                stt->push(node->right);
            }        
            
            if(st->empty()){
                ans.push_back(level);
                level.clear();
                
                queue<TreeNode*> *temp = stt;
                stt = st;
                st = temp;
            }
                
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};