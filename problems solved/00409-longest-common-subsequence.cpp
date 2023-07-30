class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        int up,u;
        vector<int> cur(n2+1);
        for(int index1=1; index1<=n1; index1++){
            u=0;
            for(int index2=1; index2<=n2; index2++){
                up = u;
                u = cur[index2];
                
                if(text1[index1-1] == text2[index2-1]) cur[index2] = 1 + up;
                else cur[index2] = max( u, cur[index2-1] );
            }
        }
        return cur[n2];
    }
};