class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int start = 0;
        int poison_effect = 0;
        
        for(int i=0; i<timeSeries.size(); i++){
            if(timeSeries[i] > poison_effect){
                ans += poison_effect - start;
                start = timeSeries[i];
            }
            poison_effect = timeSeries[i] + duration;
        }
        ans += poison_effect - start;
        return ans;
    }
};