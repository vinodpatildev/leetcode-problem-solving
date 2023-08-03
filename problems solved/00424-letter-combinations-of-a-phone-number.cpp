class Solution {
    string strel(int n){
        switch(n){
            case 2:return "abc";break;
            case 3:return "def";break;
            case 4:return "ghi";break;
            case 5:return "jkl";break;
            case 6:return "mno";break;
            case 7:return "pqrs";break;
            case 8:return "tuv";break;
            case 9:return "wxyz";break;
            default:return "";
                
        }
    }
    void rec(string& unit, int it, const string& digits, vector<string>& res){
        if(it == digits.size()) {
            if(unit != "") res.push_back(unit);
            return;
        }
        string mapped_string = strel(digits[it]-'0');
        for(auto ch : mapped_string){
            unit.push_back(ch);
            rec(unit,it+1,digits,res);
            unit.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string unit;
        rec(unit,0,digits,res);
        return res;
    }
};