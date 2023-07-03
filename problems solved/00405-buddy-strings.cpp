class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        vector<int> v;
        for(int it=0; it<s.size(); it++) if(s[it] != goal[it]) v.push_back(it);
        if (v.size() == 2) return s[v[0]] == goal[v[1]] && s[v[1]] == goal[v[0]];
        if(v.size() > 2) return false;
        sort(s.begin(),s.end());
        sort(goal.begin(),goal.end());
        if(s != goal) return false;
        for(int it=1; it<s.size(); it++) if(s[it] == s[it-1]) return true;
        return false;
    }
};