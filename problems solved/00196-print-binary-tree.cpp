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
    int height(TreeNode* root){
        if(!root){return 0;}
        return max(height(root->left),height(root->right)) + 1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int row = height(root);
        int col = (1<<row)-1;
        vector<vector<string>> matrix(row,vector<string>(col,""));
        queue<pair<TreeNode*,int>> todo;
        todo.push({root,(col-1)/2});

        int r = 0;
        while(!todo.empty()){
            int size = todo.size();
            for(int i=0; i<size; i++){
                auto element = todo.front(); todo.pop();
                TreeNode* node = element.first;
                int c = element.second;
                matrix[r][c] = to_string(node->val);
                if(node->left){todo.push({node->left,c-(1<<(row-r-2))});}
                if(node->right){todo.push({node->right,c+(1<<(row-r-2))});}
            }
            r++;
        }
        return matrix;
    }
};