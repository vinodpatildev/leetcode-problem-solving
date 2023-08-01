class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        vector<int> prev(s2+1), cur(s2+1);
        for(int j=0; j<=s2; j++) prev[j] = j;
        for(int i=1; i<=s1; i++){
            cur[0] = i;
            for(int j=1; j<=s2; j++){
                if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];
                else cur[j] = 1 + min(prev[j-1],min(prev[j],cur[j-1]));
            }
            prev = cur;
        }
        return prev[s2];
    }
};