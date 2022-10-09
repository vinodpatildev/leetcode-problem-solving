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
    void findPaths(TreeNode* root, vector<string>& paths,string path){
        if(!root){return;}
        path += to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(path); return;
        }
        path += "->";
        findPaths(root->left,paths,path);
        findPaths(root->right,paths,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        findPaths(root,paths,"");
        return paths;
    }
};