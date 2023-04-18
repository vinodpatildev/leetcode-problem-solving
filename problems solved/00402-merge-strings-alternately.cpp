class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        bool flag = true;
        int size = word1.size() + word2.size();
        int it1=0, it2=0;
        for(int it=0; it<size; it++){
            if(flag){
                if(it1<word1.size()){
                    ans += word1[it1++];
                }else{
                    ans += word2[it2++];
                }
            }
            else{
                if(it2<word2.size()){
                    ans += word2[it2++];
                }else{
                    ans += word1[it1++];
                }
            }
            flag = !flag;
        }
        return ans;
    }
};