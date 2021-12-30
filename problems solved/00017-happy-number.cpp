class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7){
            return true;
        }else if(n<10){
            return false;
        }
        int ans = 0;
        while(n){
            int i = n%10;
            ans += i*i;
            n = n/10;
        }
        return isHappy(ans);
    }
};