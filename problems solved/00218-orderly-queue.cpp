class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res = s;
        if(k==1){
            for(int i=0; i<s.size(); i++) res = min(res,s.substr(i) + s.substr(0,i));
            return res;
        }
        sort(res.begin(),res.end());
        return res;
    }
};