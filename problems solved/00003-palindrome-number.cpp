class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long x1 = x;
        long x2 = 0;
        
        if(x<0)
            return false;
        
        while(temp!=0){
            x2 = 10*x2 + temp%10;
            temp = temp/10;
        }
        return x1==x2;
    }
};