class Solution {
public:
    string convertToString(string str){
        int sizeStr = str.size();
        string palindrome = "";
        for(int i=0; i<sizeStr; i++){
            if(str[i]>=48 && str[i]<=57){
                palindrome += str[i];
            }else if(str[i]>=97 && str[i]<=122){
                palindrome += str[i];
            }else if(str[i]>=65 && str[i]<=90){
                palindrome += str[i]+32;
            }
        }
        return palindrome;
    }
    bool isPalindrome(string s) {
        string str = convertToString(s);
        int sizeStr = str.size();
        if(sizeStr==0){
            return true;
        }
        for(int i=0; i<=sizeStr/2; i++){
            if(str[i]!=str[sizeStr-1-i]){
                return false;
            }
        }
        return true;
    }
};