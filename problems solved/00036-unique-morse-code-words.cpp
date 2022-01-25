class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> map;
        int t=0,size,index,i,j;
        string str,mstr;
        for(i=0; i<words.size(); i++){
            str = words[i];
            size = str.size();
            mstr = "";
            for(j=0; j<size; j++){
                index = int(str[j]-'a');
                mstr += morse[index];
            }
            if(!map[mstr]){
                t++;
                map[mstr] = 1;
            }
        }
        return t;
    }
};