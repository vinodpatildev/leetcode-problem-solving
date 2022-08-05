class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> task(26,0), check(26,0);
        for(char c:s){
            task[c-'a']++;
        }
        for(char c:t){
            check[c-'a']++;
        }
        if(task==check){return true;}
        else{return false;}
    }
};