class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char,string> mp;
        unordered_map <string,int> word_map;
        istringstream in(s);
        int i=0;
        for(string word; in >> word; ++i){
            if(mp.find(pattern[i]) != mp.end()) {
                if(mp[pattern[i]] != word) return false;
            }else if(word_map.find(word) == word_map.end()){
                mp[pattern[i]] = word;
                word_map[word]++; 
            }else{
                return false;
            }
        }
        if(i<pattern.size()) return false;
        return true;
    }
};