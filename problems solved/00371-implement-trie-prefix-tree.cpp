class Trie {
    class TrieNode{
        public:
        char data;
        bool ends;
        vector<TrieNode*> children; 
        TrieNode(char ch){
            data = ch;
            ends = false;
            children.resize(26,NULL);
        }
    };
    TrieNode* root;
    bool rec(TrieNode* root){
        if(root == NULL) return false;
        if(root->ends) return true;
        for(int it=0; it<26; it++){
            if(rec(root->children[it])) return true;
        }
        return false;
    }
public:
    Trie() {
        root = new TrieNode(' ');
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int it=0; it<word.size(); it++){
            char x = word[it];
            if(node->children[x-'a'] == NULL){
                node->children[x-'a'] = new TrieNode(x);
            }
            node = node->children[x-'a'];
        }
        node->ends = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int it=0; it<word.size(); it++){
            char x = word[it];
            if(node->children[x-'a'] == NULL) return false;
            node = node->children[x-'a'];
        }
        return node->ends;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int it=0; it<=prefix.size(); it++){
            if(it==prefix.size()){
                return rec(root);
            }
            char x = prefix[it];
            if(node->children[x-'a'] == NULL) return false;
            node = node->children[x-'a'];
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */