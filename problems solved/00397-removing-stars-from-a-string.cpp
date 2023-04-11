class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int count = 0;
        for(int it=s.size()-1; it>=0; it--){
            if(s[it]=='*') count++;
            else{
                if(count==0){
                    ans += s[it];
                }else{
                    count--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};