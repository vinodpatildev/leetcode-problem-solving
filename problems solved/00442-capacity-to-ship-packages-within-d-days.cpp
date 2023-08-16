class Solution {
public:
    int shipWithinDays(const vector<int>& weights,const int days) {
        int packages = weights.size();
        int minCap = *max_element(weights.begin(),weights.end());
        int maxCap = 0;
        for(int w : weights) maxCap += w;
        int ans = maxCap;

        while(minCap <= maxCap){
            int midCap = (minCap+maxCap)/2;

            int day = 0;
            int cap = 0;
            for(int it=0; it<packages; it++){
                if(cap + weights[it] <= midCap) cap += weights[it];
                else { day++; cap = weights[it];}
            }
            if(cap <= midCap) day++;
            if(day <= days) { ans = midCap; maxCap = midCap-1;}
            else minCap = midCap+1;
        }
        return ans;
    }
};