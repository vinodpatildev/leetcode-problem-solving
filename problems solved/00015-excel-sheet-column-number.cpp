class Solution {
public:
    int returnInt(char c){
        if(c=='Z'){
            return 26;
        }
        return (int)(c-65+1);
    }
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();
        if(size==0){
            return 0;
        }else if(size==1){
            return returnInt(columnTitle[0]);
        }
        return 26*titleToNumber(columnTitle.substr(0,size-1)) + returnInt(columnTitle[size-1]);
        
    }
};