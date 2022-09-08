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
    void helper(TreeNode* node ,priority_queue<int,vector<int>,greater<int>> &pq, set<int> &s){
       
        if(node->left){
            helper(node->left,pq,s);
        }
        
        if(s.find(node->val) == s.end()){
            s.insert(node->val);
            pq.push(node->val);
        }
        
        if(node->right){
            helper(node->right,pq,s);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        priority_queue<int,vector<int>,greater<int>> pq;
        set<int> s;
        helper(root,pq,s);
        
        if(pq.size()<2){return -1;}
        pq.pop();
        return pq.top();
    }
};