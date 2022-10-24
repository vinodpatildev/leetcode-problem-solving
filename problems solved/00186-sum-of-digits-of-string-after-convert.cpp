class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for(char ch : s){
            int char_num = ch - 'a' + 1;
            res += char_num/10 + char_num%10;
        }
        while(--k){
            int num = 0;
            while(res){
                num += res%10;
                res = res/10;
            }
            res = num;
        }
        return res;
    }
};