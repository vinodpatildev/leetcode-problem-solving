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
    vector<double> averageOfLevels(TreeNode* root) {
        stack<TreeNode*> *st = new stack<TreeNode*>();
        stack<TreeNode*> *stt = new stack<TreeNode*>();
        vector<double> ans;
        double sum = 0.0;
        int count = 0;
        
        st->push(root);
        
        while(!st->empty()){
            TreeNode* node = st->top();
            st->pop();
            
            if(node->left){
                stt->push(node->left);
            }
            if(node->right){
                stt->push(node->right);
            }        
            
            sum += node->val;
            count++;
            
            if(st->empty()){
                ans.push_back(sum/count);
                sum = 0.0;
                count = 0;
                
                stack<TreeNode*> *temp = stt;
                stt = st;
                st = temp;
            }
                
        }
        return ans;
        
    }
};