class Solution {
public:
    bool isCap(char ch){
        return ch>='A' && ch<='Z';
    }
    bool isSmall(char ch){
        return ch>='a' && ch<='z';
    }
    bool detectCapitalUse(string word) {
        int it=0;
        if(isCap(word[it])){
            it++;
            if(it<word.size() && isCap(word[it])){
                while(it<word.size()){
                if(isCap(word[it])) it++;
                else return false;
            }
            }else if(it<word.size() && isSmall(word[it])){
                 while(it<word.size()){
                if( isSmall(word[it]) ) it++;
                else return false;
                }
            }
        }else if(isSmall(word[it])){
            while(it<word.size()){
                if(isSmall(word[it])) it++;
                else return false;
            }
        }
        return true;
    }
};