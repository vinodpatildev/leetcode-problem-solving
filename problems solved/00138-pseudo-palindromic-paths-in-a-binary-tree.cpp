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
    int helper(TreeNode* node, vector<int>& mask){
        int ans = 0;
        int flag = 0;
        if(mask[node->val-1]){
            flag = 1;
            mask[node->val-1] = 0;
        }else{
            mask[node->val-1] = 1;
        }   
        
        int count1=0,count2=0;
        if(node->left){count1 = helper(node->left, mask);}
        if(node->right){count2 = helper(node->right, mask);}
        
        if(node->left==NULL && node->right==NULL){
            int c=0;
            for(int i=0; i<mask.size(); i++){
                if(mask[i]){c++;}
            }
            if(c==0 || c==1){
                ans = 1;
            }else{
                ans = 0;
            }
        }
        if(flag){
            mask[node->val-1] = 1;
        }else{
            mask[node->val-1] = 0;
        }
        return ans + count1 + count2;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mask(9,0);
        return helper(root,mask);
    }
};