class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map <char,int> charMap1,charMap2;
        set<char> charSet1,charSet2;
        for(char ch:word1) charMap1[ch]++, charSet1.insert(ch);
        for(char ch:word2) charMap2[ch]++, charSet2.insert(ch);
        int charDiff = charSet1.size()-charSet2.size();
        charDiff = abs(charDiff);
        if(charDiff==0) {
            for(auto p:charMap1){
                if(p.second==1){
                    for(auto p2:charMap2){
                        if(p2.second==1) return true;
                    }
                }
                else if(p.second>1){
                    for(auto p2:charMap2){
                        if(p2.second>1) return true;
                    }
                }
            }
            return false;
        }
        else if(charDiff==1){
            if(charSet1.size() > charSet2.size()){
                for(auto p:charMap2){
                    if(p.second > 1 && charMap1[p.first]){
                        for(auto p2:charMap1){
                            if(p2.second>1 && !charMap2[p2.first]) return true;
                        }
                    }
                    if(p.second == 1 && charMap1[p.first]){
                        for(auto p2:charMap1){
                            if(p2.second==1 && !charMap2[p2.first]) return true;
                        }
                    }                    
                }
                return false;
            }
            return isItPossible(word2,word1);
        }else if(charDiff==2){
            if(charSet1.size() > charSet2.size()){
                for(auto p:charMap2){
                    if(p.second > 1 && charMap1[p.first]){
                        for(auto p2:charMap1){
                            if(p2.second==1 && !charMap2[p2.first]) return true;
                        }
                    }
                }
                return false;
            }
            return isItPossible(word2,word1);
        }
        return false;
    }
};