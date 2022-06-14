class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){return false;}
        int count_one = 0;
        while( n ){
            if( n & 1 ){
                count_one++;
            }
            n = n>>1;
        }
        if(count_one == 1 ){
            return true;
        }
        return false;
    }
};