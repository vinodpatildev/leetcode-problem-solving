class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
        if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans, vector<string> &part, string &s, int index){
        if(index==s.size()){
            ans.push_back(part);
        }
        
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s,index,i)){
                part.push_back(s.substr(index,i-index+1));
                helper(ans,part,s,i+1);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        
        helper(ans,part,s,0);
        return ans;
    }
};