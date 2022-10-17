class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> letter(26,0);
        for(int i=0; i<sentence.size(); i++){
            letter[sentence[i]-'a'] = 1;
        }
        for(int x:letter){
            if(x==0){return false;}
        }
        return true;
    }
};