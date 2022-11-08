class Solution {
public:
    string makeGood(string s) {
        stack<char> todo;
        string res;
        for(char ch : s){
            if(todo.empty()) todo.push(ch);
            else if(todo.top()-'a' == ch-'A' || todo.top()-'A' == ch-'a') todo.pop();
            else todo.push(ch);
        }
        while(!todo.empty()) res = todo.top() + res, todo.pop();
        return res;
    }
};