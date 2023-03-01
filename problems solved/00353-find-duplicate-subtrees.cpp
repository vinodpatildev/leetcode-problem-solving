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
    string postorder(TreeNode* root, set<TreeNode*>& res, unordered_map <string,TreeNode*>& mp){
        if(root == NULL) return "N";
        string l = postorder(root->left,res,mp);
        string r = postorder(root->right,res,mp);
        string post = to_string(root->val) + "-" + l + "-" + r;
        if(mp.find(post) != mp.end()) res.insert(mp[post]);
        else mp[post] = root;
        return post;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        set<TreeNode*>  res;
        unordered_map <string,TreeNode*> mp;
        postorder(root,res,mp);
        vector<TreeNode*> ans;
        for(auto element : res) ans.push_back(element);
        return ans;
    }
};