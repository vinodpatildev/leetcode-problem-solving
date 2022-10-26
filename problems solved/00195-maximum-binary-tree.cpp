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
    int part(vector<int>& nums,int begin,int end){
        int index = begin;
        for(int i=begin; i<=end; i++){
            if(nums[i]>nums[index]){ index = i; }
        }
        return index;
    }
    TreeNode* helper(vector<int>& nums,int begin,int end){
        if(begin>end){return NULL;}
        int partIndex = part(nums,begin,end);
        TreeNode* root = new TreeNode(nums[partIndex]);
        root->left = helper(nums,begin,partIndex-1);
        root->right = helper(nums,partIndex+1,end);
        return root;        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){return NULL;}
        return helper(nums,0,nums.size()-1);
    }
};