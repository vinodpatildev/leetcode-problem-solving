class Solution {
public:
    bool canPlaceFlowers(vector<int>& fbed, int n) {
        int prev = 0, next = 0, count = 0;
        vector<int> bed = fbed;
        for(int i=0; i<bed.size(); i++){
            if(count == n) break;
            if(!bed[i]){
                prev = (i==0)? 0 : bed[i-1];
                next = (i==bed.size()-1)? 0 : bed[i+1];
                if(!prev && !next){
                    count++;
                    bed[i] = 1;
                }
            }
        }
        return count == n;
    }
};