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
    stack<TreeNode*> left,right;
    void addAllLeft(TreeNode* root){
        while(root){
            left.push(root);
            root = root->left;
        }
    }
    void addAllRight(TreeNode* root){
        while(root){
            right.push(root);
            root = root->right;
        }
    }
    // TreeNode* leftNext(){
    //     if(!leftHasNext()){return NULL;}
    // }
    // TreeNode* rightNext(){
    //     if(!rightHasNext()){return NULL;}
    // }
    TreeNode* leftNext(){
        if(!leftHasNext()){return NULL;}
        TreeNode* node = left.top(); left.pop();
        addAllLeft(node->right);
        return node;
    }
    TreeNode* rightNext(){
        if(!rightHasNext()){return NULL;}
        TreeNode* node = right.top(); right.pop();
        addAllRight(node->left);
        return node;
    }
    bool leftHasNext(){return !left.empty();}
    bool rightHasNext(){return !right.empty();}

    bool findTarget(TreeNode* root, int k) {
        addAllLeft(root);
        addAllRight(root);

        TreeNode *left,*right;
        left = leftNext();
        right = rightNext();
        while(left && right && left->val < right->val){
            int sum = left->val + right->val;
            if(sum == k){return true;}
            if(sum < k){
                left = leftNext();
            }else{
                right = rightNext();
            }
        }
        return false;
    }
};