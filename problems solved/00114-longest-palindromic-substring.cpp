class Solution {
public:
    int maxLengthPalindrome(string &s,int s_begin,int s_end, int i, int j){
        while(i>=s_begin && j<=s_end){
            if(s[i] != s[j]){
                return j-i-1;
            }
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int s_size = s.size();
        int largestPalindromLength = 0;
        int largestPalindromLeft = -1;
        int largestPalindromRight = -1;
        int l1,l2,len;
        for(int i=0; i<s_size; i++){
            l1 = maxLengthPalindrome(s,0,s_size-1,i,i);
            l2 = maxLengthPalindrome(s,0,s_size-1,i,i+1);
            len = max(l1,l2);
            if(len>largestPalindromLength){
                largestPalindromLeft = i-(len-1)/2;
                largestPalindromRight = i+len/2;
                largestPalindromLength = len;
            }            
        }
        return s.substr(largestPalindromLeft,largestPalindromLength);
    }
};