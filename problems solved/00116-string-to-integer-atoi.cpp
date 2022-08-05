#include <iostream>
#include<ctype.h>
class Solution {
public:
    int myAtoi(string s) {
        long int ans = 0;
        int sign = 1,i = 0;
        while(s[i]==' '){i++;}
        if(s[i]=='+' || s[i]=='-'){
            sign = 1-2*(s[i]=='-');
            i++;
        }
        while(isdigit(s[i])){
            ans = (ans*10) + (s[i++]-'0');
            if(sign*ans<INT_MIN){return INT_MIN;}
            else if(sign*ans>INT_MAX){return INT_MAX;}
        }
        return sign*ans;
    }
};