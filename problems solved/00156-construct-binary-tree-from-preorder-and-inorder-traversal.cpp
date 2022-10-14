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
   TreeNode* helper(vector<int>& inorder,vector<int>& preorder,int inBegin,int inEnd, int& preId, unordered_map<int,int>& mpp){
        if(inBegin>inEnd){return NULL;}
        TreeNode* root = new TreeNode(preorder[preId++]);
        
        int inRoot = mpp[root->val];
        
        root->left = helper(inorder,preorder,inBegin,inRoot-1, preId, mpp);
        root->right = helper(inorder,preorder,inRoot+1,inEnd, preId, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int preId = 0;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        return helper(inorder,preorder,0,inorder.size()-1,preId,mpp);
    }
};