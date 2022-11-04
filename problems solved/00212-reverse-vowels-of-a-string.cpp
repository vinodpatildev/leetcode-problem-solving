class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
        string res = s;
        int left=0,right=res.size()-1;
        while(left<right){
            while(left<right && vowels.find(res[left]) == vowels.end()) left++;
            while(left<right && vowels.find(res[right]) == vowels.end()) right--;

            char ch = res[left];
            res[left] = res[right];
            res[right] = ch;
            left++;
            right--;         
        }
        return res;
    }
};