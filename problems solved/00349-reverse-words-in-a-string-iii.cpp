class Solution {
public:
    string reverseWords(string s) {
        string str = s;
        string::iterator start,end;
        start = end = str.begin();
        while(end != str.end()){
            if(*end == ' '){
                reverse(start,end);
                start = end+1;
            }
            end++;
        }
        if(end==str.end()){
            reverse(start,end);
        }
        return str;
    }
};