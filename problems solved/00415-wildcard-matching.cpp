class Solution {
    bool fun(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(j<0) return i<0;
        if(i<0) {
            while(j>=0) if(p[j--] != '*') return false;
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;
        if(p[j] == '*') ans = fun(i,j-1,s,p,dp) || fun(i-1,j,s,p,dp);
        else if(p[j] == '?' || p[j] == s[i]) ans = fun(i-1,j-1,s,p,dp);
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector(m+1,false));
        vector<bool> prev(m+1,false), cur(m+1);
        prev[0] = true;
        for(int j=1; j<=m; j++) prev[j] = p[j-1]=='*' && prev[j-1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*') cur[j] = cur[j-1] || prev[j];
                else if(p[j-1] == '?' || p[j-1] == s[i-1]) cur[j] = prev[j-1];
                else cur[j] = false;
            }
            prev = cur;
        } 

        return prev[m];
    }
};