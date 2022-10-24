class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> mpp;
        unordered_set<char> mapped;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(s[i]) != mpp.end()){
                if( mpp[s[i]] != t[i] ){
                    return false;
                }
            }else{
                if(mapped.find(t[i]) != mapped.end()){
                    return false;
                }
                mpp[s[i]] = t[i];
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};