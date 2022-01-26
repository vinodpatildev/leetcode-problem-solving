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
    void inorder(TreeNode* node, vector<int> &ans){
        if(node==NULL){return;}
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> arr1;
        vector<int> arr2;
        
        inorder(root1,arr1);
        inorder(root2,arr2);
        int i=0,j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }else{
                ans.push_back(arr2[j]);
                j++;
            }
        }   
        while(i<arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
};