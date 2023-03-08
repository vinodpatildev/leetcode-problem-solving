class Solution {
public:
    long long int check(vector<int>& timeArr, long long int time){
        long long int totalTrips = 0;
        for(auto x : timeArr){
            long long int val = x;
            totalTrips += (time/x);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int lt = 1, ht = 1e14;
        while(lt < ht){
            long long int mid = (lt+ht)/2;
            if(check(time,mid) >= totalTrips){
                ht = mid;
            }else{
                lt = mid+1;
            }
        }
        return lt;
    }
};