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
    int preorder(TreeNode* root)
    {
        if(root)
        {
            int left = preorder(root->left);
            int right = preorder(root->right);
            return root->val += left + right;
        }
        return 0;
    }
    
    void helper(TreeNode* root, int whole, int& res)
    {
        if(root)
        {
            helper(root->left, whole, res);
            helper(root->right, whole, res);
            if(abs(whole - 2 * root->val) < abs(whole - 2 * res))
                res = root->val;
        }
    }
    
    int maxProduct(TreeNode* root)
    {
        int res = 0;
        int mod = 1e9 + 7;
        int whole = preorder(root);      
        helper(root, whole, res);
        long long int ret = (long long int)(((whole - res) % mod) * (long long int)(res % mod));
        return ret % mod;
    }
};