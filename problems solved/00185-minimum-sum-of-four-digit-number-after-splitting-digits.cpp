class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        int num1=0,num2=0;
        while(num){
            digits.push_back(num%10);
            num = num/10;
        }
        sort(digits.begin(), digits.end());
        num1 = digits[0];
        num2 = digits[1];
        num1 = num1*10 + digits[2];
        num2 = num2*10 + digits[3];
        return num1 + num2;        
    }
};