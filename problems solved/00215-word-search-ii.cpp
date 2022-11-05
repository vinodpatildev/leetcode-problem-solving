class Solution {
public:
    class TrieNode{
        public:
            string word;
            vector<TrieNode*> next;
            TrieNode(){next.resize(26,0);}
    };
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(string word : words){
            TrieNode* curr = root;
            for(char ch : word){
                if(curr->next[ch-'a']==NULL) curr->next[ch-'a'] = new TrieNode();
                curr = curr->next[ch-'a'];
            }
            curr->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* root, vector<string>& words, vector<string>& res){
        char ch = board[row][col];
        if(ch=='#' || root->next[ch-'a']==NULL) return;
        TrieNode* curr = root->next[ch-'a'];
        if(!curr->word.empty()) {
            res.push_back(curr->word);
            curr->word = "";
        }
        board[row][col] = '#';
        if(row>0) dfs(board, row-1, col, curr, words, res);
        if(row<board.size()-1) dfs(board, row+1, col, curr, words, res);
        if(col>0) dfs(board, row, col-1, curr, words, res);
        if(col<board[0].size()-1) dfs(board, row, col+1, curr, words, res);

        board[row][col] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++) {
                dfs(board,row,col,root,words,res);
            }
        }
        return res;
    }
};