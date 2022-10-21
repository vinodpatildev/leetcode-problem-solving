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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root){return root;}
        queue<TreeNode*> todo;
        deque<TreeNode*> odd;
        queue<TreeNode*> next;

        todo.push(root);
        while(!todo.empty()){
            int size_todo = todo.size();
            for(int i=0; i<size_todo; i++){
                TreeNode* curr = todo.front(); todo.pop();
                odd.push_back(curr->left);
                odd.push_back(curr->right);
                todo.push(curr);
            }
            int size_odd = odd.size();
            for(int i=0; i<size_odd; i++){
                TreeNode* curr = odd.front(); odd.pop_front();
                if(curr){
                    next.push(curr->left);
                    next.push(curr->right);
                }
                odd.push_back(curr);
            }
            for(int i=0; i<size_todo; i++){
                TreeNode* curr = todo.front(); todo.pop();
                curr->left = odd.back(); odd.pop_back();
                curr->right = odd.back(); odd.pop_back();
                // todo.push(curr);
                odd.push_front(curr->left);
                odd.push_front(curr->right);
            }
            for(int i=0; i<size_odd; i++){
                TreeNode* curr = odd.back(); odd.pop_back();
                if(curr){
                    curr->left = next.front(); next.pop();
                    curr->right = next.front(); next.pop();
                    
                    if(curr->left){todo.push(curr->left);}
                    if(curr->right){todo.push(curr->right);}
                }
            }
        }
        return root;
    }
};