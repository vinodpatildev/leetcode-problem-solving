class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        if(s.size()==0) return res = "";
        stack<char> todo;
        for(int i=0; i<s.size(); i++){
            if(todo.empty() || todo.top() != s[i]){
                todo.push(s[i]);
            }else{
                todo.pop();
            }
        }
        while(!todo.empty()){
            res += todo.top();
            todo.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};