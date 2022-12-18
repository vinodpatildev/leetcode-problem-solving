class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        vector<bitset<26>> wordsBitset(words.size());
        for(int i=0; i<words.size(); i++){
            bitset<26> wordset;
            for(int j=0; j<words[i].size(); j++){
                wordset[words[i][j]-'a'] = 1;
            }
            wordsBitset[i] = wordset;
        }
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(wordsBitset[i] == wordsBitset[j]) res++;
            }
        }
        return res;
    }
};