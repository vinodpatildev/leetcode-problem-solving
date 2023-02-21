class Solution {
public:
    string reverseStr(string s, int k) {
        string::iterator it = s.begin();
        for(int i=0; i<s.size(); i += 2*k){
            int it2 = min((int)s.size(),i+k);
            reverse(it+i,it+it2);
        }
        return s;
    }
};