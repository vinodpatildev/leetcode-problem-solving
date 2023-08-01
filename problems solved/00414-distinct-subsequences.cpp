class Solution {
public:
    int numDistinct(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
        vector<int> cur(size_t+1);
        int up,u;
        u = cur[0] = 1;
        for(int i=1; i<=size_s; i++){
            u = 1;
            for(int j=1; j<=size_t; j++){
                up = u;
                u = cur[j];
                long ans = 0;
                if(s[i-1] == t[j-1]) ans = (long) up + u;
                else ans = u;
                cur[j] = ans;
            }
        }
        return cur[size_t];
    }
};