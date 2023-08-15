class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int days = bloomDay.size();
        int minDays = *min_element(bloomDay.begin(),bloomDay.end());
        int maxDays = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(minDays <= maxDays){
            int midDays = (minDays + maxDays)/2;
            
            int bouquets = 0;
            int bouquetsFlowerCount = 0;
            for(int day=0; day<days; day++){
                if(bloomDay[day] <= midDays) bouquetsFlowerCount++;
                else bouquetsFlowerCount = 0;
                
                if(bouquetsFlowerCount == k){
                    bouquets++;
                    bouquetsFlowerCount = 0;
                }
            }
            if(bouquets >= m){
                ans = midDays;
                maxDays = midDays-1;
            }
            else{
                minDays = midDays+1;
            }
        }
        return ans;
    }
};