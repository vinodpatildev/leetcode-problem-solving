class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push('(');
            }else if(s[i]=='{'){
                st.push('{');
            }else if(s[i]=='['){
                st.push('[');
            }else if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }                
            }else if(!st.empty() && s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }else if(!st.empty() && s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return st.empty();
    }
};