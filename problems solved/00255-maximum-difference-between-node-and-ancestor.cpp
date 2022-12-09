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
    void inorder(TreeNode* root, int& maxElement, int& minElement, int& res){
        if(!root) return;
        if(root->val > maxElement) maxElement = root->val;
        if(root->val < minElement) minElement = root->val;
        res = max(res,abs(maxElement-minElement));
        int tempMaxElement = maxElement, tempMinElement = minElement;
        inorder(root->left,maxElement,minElement,res);
        maxElement = tempMaxElement; minElement = tempMinElement;
        inorder(root->right,maxElement,minElement,res);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxElement=INT_MIN,minElement=INT_MAX,res=INT_MIN;
        inorder(root,maxElement,minElement,res);
        return res;
    }
};