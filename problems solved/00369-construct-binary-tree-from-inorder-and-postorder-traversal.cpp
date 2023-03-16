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
    int postId = 0;
    vector<int> in,post;
    TreeNode* build(int inStart, int inEnd){
        if(inStart > inEnd) return NULL;
        int dataIndex = find(in.begin(),in.end(),post[postId]) - in.begin();
        TreeNode* root = new TreeNode(post[postId--]);
        root->right = build(dataIndex+1,inEnd);
        root->left = build(inStart,dataIndex-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        postId = inorder.size()-1;
        return build(0,inorder.size()-1);
    }
};