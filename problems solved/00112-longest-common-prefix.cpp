class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        int i,j;
        for(i=1; i<strs.size(); i++){
            for(j=0; j<str.size()&&j<strs[i].size(); j++){
                if(str[j]!=strs[i][j]){
                    str = str.substr(0,j);
                    break;
                }
            }
            if(strs[i].size()<str.size()){
                str = str.substr(0,strs[i].size());
            }
        }
        return str;
    }
};