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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> *st = new queue<TreeNode*>();
        queue<TreeNode*> *stt = new queue<TreeNode*>();
        int sum = 0;
        if(root){
            st->push(root);
        }
        
        while(!st->empty()){
            TreeNode* node = st->front();
            st->pop();
            sum += node->val;
            
            if(node->left){
                stt->push(node->left);
            }
            if(node->right){
                stt->push(node->right);
            }        
            
            if(st->empty()){
                if(stt->empty()){return sum;}
                sum = 0;
                
                queue<TreeNode*> *temp = stt;
                stt = st;
                st = temp;
            }
                
        }
        return 0; 
    }
};