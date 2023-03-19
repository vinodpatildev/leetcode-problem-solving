class WordDictionary {
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
    TrieNode* root = NULL;
    bool match(string& word, int index, TrieNode* node) {
        if(index == word.size()) return node->ends;
        if(word[index] == '.'){
            for(TrieNode* child : node->children){
                if(child && match(word,index+1,child)) return true;
            }
        }else if(node->children[word[index]-'a']) return match(word,index+1,node->children[word[index]-'a']);
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode(' ');
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char x : word){
            if(node->children[x-'a'] == NULL)  node->children[x-'a'] = new TrieNode(x);
            node = node->children[x-'a'];
        }
        node->ends = true;
    }
    
    bool search(string word) {
        return match(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

