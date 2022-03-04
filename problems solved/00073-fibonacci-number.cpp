class Solution {
public:
    int fib(int n) {
        int first=0;
        int second=1;
        if(n==0){return first;}
        else if(n==1){return second;}
        int iterator=2;
        int fibCurr;
        while(iterator<=n){
            fibCurr=first+second;
            first=second;
            second=fibCurr;
            
            iterator++;
        }
        return fibCurr;        
    }
};