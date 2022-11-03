class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nc = abs(n);
        while(nc){
            if(nc&1){
                ans *= x;
            }
            nc = nc >> 1;
            x *= x;
        }
        return n<0? 1.0/(ans) : ans;        
    }
};