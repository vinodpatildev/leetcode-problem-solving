/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        if(!root){return data;}
        queue<TreeNode*> todo;
        todo.push(root);

        while(!todo.empty()){
            int size = todo.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = todo.front(); todo.pop();
                if(curr){
                    data += to_string(curr->val) + ",";
                    todo.push(curr->left);
                    todo.push(curr->right);
                }else{
                    data += "#,";
                }
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){return NULL;}
        stringstream tokenizer(data);
        string token;
        getline(tokenizer,token,',');

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            int size = todo.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = todo.front(); todo.pop();
                getline(tokenizer,token,',');
                if(token=="#"){
                    curr->left = NULL;
                }else{
                    curr->left = new TreeNode(stoi(token));
                    todo.push(curr->left);
                }

                getline(tokenizer,token,',');
                if(token=="#"){
                    curr->right = NULL;
                }else{
                    curr->right = new TreeNode(stoi(token));
                    todo.push(curr->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));