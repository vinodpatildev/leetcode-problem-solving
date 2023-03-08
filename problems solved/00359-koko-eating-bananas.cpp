class Solution {
public:
    bool check(vector<int>& piles, int h,int mid){
        int res = 0;
        for(auto pile : piles){
            res += (pile/mid);
            if(pile%mid) res++;
        }
        return res <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = (l+r)/2;
            if(check(piles,h,mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};