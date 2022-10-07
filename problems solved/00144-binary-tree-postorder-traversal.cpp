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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> preorder;
        vector<int> inorder;
        vector<int> postorder;
        if(root==NULL){return inorder;}
        stack<pair<TreeNode*,int>> st;
        st.push(make_pair(root,1));
        while(!st.empty()){
            pair<TreeNode*,int> node = st.top();
            if(node.second==1){
                preorder.push_back(node.first->val);
                st.top().second = 2;
                if(node.first->left){st.push(make_pair(node.first->left,1));}
            }else if(node.second==2){
                inorder.push_back(node.first->val);
                st.top().second = 3;
                if(node.first->right){st.push(make_pair(node.first->right,1));}
            }else if(node.second==3){
                postorder.push_back(node.first->val);
                st.pop();
            }          
        }
        return postorder;
    }
};