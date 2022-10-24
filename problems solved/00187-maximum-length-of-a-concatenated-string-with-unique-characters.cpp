class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        vector<bitset<26>> dp = {bitset<26>()};
        for(string& str : arr){
            bitset<26> str_bit; 
            for(char c:str){
                str_bit.set(c-'a');
            }
            int n = str_bit.count();
            if( n < str.size()){continue;}
            for(int i=dp.size()-1; i>=0; i--){
                bitset<26> dp_bit = dp[i];
                if((str_bit & dp_bit).any()){continue;}
                dp.push_back(str_bit | dp_bit);
                res = max( res, n + (int)dp_bit.count() );
            }
        }
        return res;
    }
};