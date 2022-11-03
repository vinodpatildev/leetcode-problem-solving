class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        unordered_set<string> mset;
        int res = 0;
        for(int i=0; i<words.size(); i++){
            string word = words[i];
            if(mpp[word]){
                res += 4;
                if(mpp[word]==1){
                    mpp.erase(word);
                }else{
                    mpp[word]--;
                }
            }else{
                reverse(word.begin(),word.end());
                mpp[word]++;
            }
        }
        for(auto mappings : mpp){
            string word = mappings.first;
            if(word[0] == word[1]){
                return res + 2;
            }
        }
        return res;
    }
};