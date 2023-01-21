 class Solution {
public:
    bool check(string& s, int index, int len){
        if(s[index]=='0') return len==1;
        if(len==3) return s.substr(index,len) <= "255";
        return true;
    }
    void rec(vector<string>& res,string& s, string& ip, int dots, int index){
        if(dots==0){
            if(s.size()-index>3 || s.size()-index==0) return;
            if(check(s,index,s.size()-index)){
                ip.append(s.substr(index,s.size()-index));
                res.push_back(ip);
                for(int x=0; x<s.size()-index; x++) ip.pop_back();
            }
        }
        for(int len=1; len<=3; len++){
            if(index + len <= s.size() && check(s,index,len)) {
                ip.append(s.substr(index,len));
                ip.append(".");
                rec(res,s,ip,dots-1,index+len);
                ip.pop_back();
                for(int x=0; x<len; x++) ip.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()>12) return res;
        string ip;
        rec(res,s,ip,3,0);
        return res;
    }
};