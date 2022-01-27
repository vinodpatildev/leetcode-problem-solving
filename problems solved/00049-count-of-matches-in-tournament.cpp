class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0,temp;
        while(n != 1){
            temp = n/2;
            if(n%2==1){temp++;}
            count += n/2;
            n = temp;
        }
        return count;
    }
};