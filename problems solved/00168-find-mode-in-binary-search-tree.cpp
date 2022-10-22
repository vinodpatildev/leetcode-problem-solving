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
    void find(TreeNode* root,unordered_map<int,int>& mpp){
        if(!root){return;}
        mpp[root->val]++;
        find(root->left,mpp);
        find(root->right,mpp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map <int,int> mpp;
        find(root,mpp);
        int f = 0;
        for(auto x:mpp){
            if(x.second>f){f=x.second;}
        }
        for(auto x:mpp){
            if(x.second==f){res.push_back(x.first);}
        }
        return res;
    }
};