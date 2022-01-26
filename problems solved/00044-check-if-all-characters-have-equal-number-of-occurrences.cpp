class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> alpha(26,0);
        for(int i=0; i<s.size(); i++){
            alpha[s[i]-'a']++;
        }
        int freq = alpha[s[0]-'a'];
        for(int i=0; i<26; i++){
            if(alpha[i]!=0 && alpha[i]!=freq){return false;}
        }
        return true;
    }
};