class Solution {
public:
    string reverseWords(string s) {
        queue<char> todo;
        stack<string> st;
        string word,res = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(todo.empty()) continue;
                word = "";
                while(!todo.empty()) word += todo.front(), todo.pop();
                st.push(word);
            }else todo.push(s[i]);
        }
        if(!todo.empty()){
            word = "";
            while(!todo.empty()) word += todo.front(), todo.pop();
            st.push(word);
        }
        while(!st.empty()){
            res += st.top(); 
            st.pop();
            if(!st.empty()) res += ' ';
        }
        return res;
    }
};