class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(),0);
        stack<int> st;
        for(int i=temp.size()-1; i>=0; i--){
            while(!st.empty() && temp[i]>=temp[st.top()]) st.pop();
            res[i] = st.empty() ? 0 : st.top()-i;
            st.push(i);
        }
        return res;
    }
};