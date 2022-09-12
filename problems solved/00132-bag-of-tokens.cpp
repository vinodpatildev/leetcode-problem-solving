class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l=0, r = tokens.size()-1;
        int score = 0, maxScore = 0;
        
        
        while(l<=r){
            if(power >= tokens[l]){
                power -= tokens[l++];
                score++;
                maxScore = max(score, maxScore);
            }else if(score > 0){
                score--;
                power += tokens[r--];
            }else{
                break;
            }
        }
        
        return maxScore;
    }
};