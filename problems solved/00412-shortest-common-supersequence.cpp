class Solution {
    string lcs(string s, string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector(m+1,-1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        string ans = "";
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                ans = s[i-1] + ans;
                i--;
                j--;
            }
            else if(dp[i][j] == dp[i][j-1]) j--;
            else if(dp[i][j] == dp[i-1][j]) i--;
        }
        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcsub = lcs(str1,str2);
        int i=0, j=0;
        int n=str1.size();
        int m=str2.size();
        string ans = "";
        for(char ch : lcsub){
            while(i<n && str1[i]!=ch) ans += str1[i++];
            i++;
            while(j<m && str2[j]!=ch) ans += str2[j++];
            j++;
            ans += ch;
        }
        while(i<n) ans += str1[i++];
        while(j<m) ans += str2[j++];
        return ans;
    }
};