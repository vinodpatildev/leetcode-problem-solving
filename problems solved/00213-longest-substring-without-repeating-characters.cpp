class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int res=0,it=0,begin=0;
        for(it=0; it<s.size(); it++){
            if(mp[s[it]] != -1) begin = max(mp[s[it]]+1,begin);
            mp[s[it]] = it;
            res = max(res,it-begin+1);
        }
        return res;
    }
};