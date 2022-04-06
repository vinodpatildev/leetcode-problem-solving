class Solution {
public:
    string customSortString(string order, string s) {
        vector<char> hash(26,0);
        string ans="";
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']++;
        }
        for(int i=0; i<order.size(); i++){
            while(hash[order[i]-'a'] > 0){
                ans += order[i];
                hash[order[i]-'a']--;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(hash[s[i]-'a'] > 0){
                ans += s[i];
                hash[s[i]-'a']--;
            }
        } 
        return ans;
    }
};