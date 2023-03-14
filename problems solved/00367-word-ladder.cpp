class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordSize = beginWord.size();
        unordered_map <string, int> wordMap;
        for(string word : wordList) wordMap[word] = 1;
        queue<string> todo;
        todo.push(beginWord);
        wordMap[beginWord] = 0;

        int level = 1;
        while(!todo.empty()){
            int size = todo.size();
            for(int stIt=0; stIt<size; stIt++){
                string wordTop = todo.front(); todo.pop();
                string word = wordTop;
                for(int it=0; it<word.size(); it++){
                    for(int charIt=0; charIt<26; charIt++){
                        char ch = 'a' + charIt;
                        if(ch == wordTop[it]) continue;
                        word[it] = ch;
                        if(word == endWord && wordMap[word]) return level + 1;
                        if(wordMap[word]) {
                            todo.push(word);
                            wordMap[word] = 0;
                        }
                    }
                    word[it] = wordTop[it];
                }
            }
            level++;
        }
        return 0;
    }
};