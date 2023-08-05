class Solution {
    class TrieNode{
        public:
            bool end;
            vector<TrieNode*> children;
            TrieNode(bool end = false){
                this->end = end;
                children.resize(26,NULL);
            }
        };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root = new TrieNode(false);
        }
        void insertWord( const string& word, TrieNode* node, int it, int size){
            if(it == size){
                node->end = true;
                return;
            }
            int ch = word[it]-'a';
            if(node->children[ch]) insertWord(word,node->children[ch],it+1,size);
            else {
                TrieNode* newNode = new TrieNode(it == size-1);
                node->children[ch] = newNode;
                insertWord(word,newNode,it+1,size);
            }
        }
        bool searchWord(const string& word, const TrieNode* node, int it, int size){
            if(it == size) return node->end;
            int ch = word[it]-'a';
            if(node->children[ch]) return searchWord(word,node->children[ch],it+1,size);
            else return false;
        }
        public:
        void insert(const string& word){
            insertWord(word,root,0,word.size());
        }
        bool search(const string& word){
            return searchWord(word,root,0,word.size());
        }
    };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        Trie* t = new Trie() ;
        for(auto word : wordDict) t->insert(word);
        vector<bool> dp(n,false);
        dp[0] = t->search(s.substr(0,1));
        for(int i=1; i<n; i++){
            string word = "";
            for(int it=i; it>=0; it--){
                word = s[it] + word;
                if(t->search(word) && (it == 0 || dp[it-1])){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};