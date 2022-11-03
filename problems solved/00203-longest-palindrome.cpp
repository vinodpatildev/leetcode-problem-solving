class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        int res = 0;
        bool flag = false;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }
        for(auto mapping : mpp){
            int count = mapping.second;
            if(count%2 == 1){
                flag = true;
                res += count - 1;
            }else{
                res += count;
            }
        }
        if(flag){ res++; }
        return res;
    }
};