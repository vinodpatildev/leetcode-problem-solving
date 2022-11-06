/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=1, right=n;
        long long mid = 0;
        while(left <= right){
            mid = ((long long)left+right)/2;
            if(guess(mid) < 0){
                right = mid-1;
            }
            else if(guess(mid) > 0){
                left = mid+1;
            }
            else{ return mid;}
        }
        return -1;
    }
};