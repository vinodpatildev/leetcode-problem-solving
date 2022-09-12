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
    void helper(TreeNode* root,vector<int> &v){
        if(root==NULL){return;}
        v.push_back(root->val);
        helper(root->left,v);
        helper(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        
        sort(v.begin(), v.end());
        int diff = 0, maxDiff = INT_MAX;
        cout<<"[";
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<"]";
        for(int i=1; i<v.size(); i++){
            diff = v[i] - v[i-1];
            if(diff<maxDiff){
                maxDiff = diff;
            }
        }
        return maxDiff;
    }
};