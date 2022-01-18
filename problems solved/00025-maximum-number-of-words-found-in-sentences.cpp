class Solution {
public:
    int numWords(string& s){
        int size = s.size();
        int count = 0;
        for(int i=0; i<size; i++){
            if(s[i]==' '){
                count++;
            }
        }
        return count+1;
    }
    int mostWordsFound(vector<string>& sentences) {
        int size = sentences.size();
        int maxWords=0;
        int temp;
        for(int i=0; i<size; i++){
            temp = numWords(sentences[i]);
            if(temp>maxWords){
                maxWords = temp;
            }
        }
        return maxWords;
    }
};