class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        unordered_set <string> suffix_group[26];
        for(string& str : ideas){
            suffix_group[str[0]-'a'].insert(str.substr(1));
        }
        for(int i=0; i<25; i++){
            for(int j=i+1; j<26; j++){
                int mutual = 0;
                for(string suffix : suffix_group[i]){
                    if(suffix_group[j].count(suffix) > 0) mutual++;
                }
                ans += 2*((suffix_group[i].size()-mutual) * (suffix_group[j].size()-mutual));
            }
        }
        return ans;
    }
};