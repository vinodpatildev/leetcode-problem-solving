class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ansbits(32,0);
        for(int num : nums){
            int pos = 32;
            while(pos--){
                if(num & (1<<pos)) ansbits[pos]++;
            }
        }
        int ans = 0;
        for(int pos=0; pos<ansbits.size(); pos++) ans += (ansbits[pos]%3)*(1<<pos);
        return ans;
    }
};