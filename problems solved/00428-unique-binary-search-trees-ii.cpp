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
    vector<TreeNode*> fun(int left, int right){
        vector<TreeNode*> res;
        if(left>right){
            res.push_back(NULL);
            return res;
        }

        for(int it=left; it<=right; it++){
            vector<TreeNode*> ltrees = fun(left,it-1);
            vector<TreeNode*> rtrees = fun(it+1,right);

            for(TreeNode* l : ltrees){
                for(TreeNode* r: rtrees){
                    TreeNode* root = new TreeNode(it);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return fun(1,n);        
    }
};