class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char,char> mpp;
        for(int it=0; it<order.size(); it++) mpp[order[it]] = 'a' + it; 
        vector<string> new_words;
        for(string& str : words){
            string word = "";
            for(char ch : str){
                word += mpp[ch];
            }
            new_words.push_back(word);
        }
        for(int it=1; it<new_words.size(); it++){
            if(new_words[it-1] > new_words[it]) return false;
        }
        return true;
    }
};