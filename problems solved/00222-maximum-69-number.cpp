class Solution {
public:
    int maximum69Number (int num) {
        int number = num, digits = 0, firstSixIndex;
        while(number) {
            digits++;
            if(number%10 == 6) firstSixIndex = digits;
            number /= 10;
        }
        return num + 3 * pow(10,firstSixIndex-1);
    }
};