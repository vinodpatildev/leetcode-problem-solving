class Solution {
public:
    string helper(string &str){
        char c = str[0];
        int i=0;
        string ans="";
        while(i<str.size()){
            int count=0;
            while(str[i]==c){
                count++;
                i++;
            }
            ans += to_string(count);
            ans.push_back(c);
            if(i<str.size()){
                c = str[i];
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++){
            ans = helper(ans);
        }
        return ans;
    }
};