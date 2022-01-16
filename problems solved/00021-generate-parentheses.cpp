class Solution {
public:
    void generate(string str, vector<string>& ans, int open, int close){
        if(open==0 && close==0){
            cout<<str<<" ";
            ans.push_back(str);
        }        
        if(open>0){
            generate(str+"(",ans,open-1,close); 
        }
        if(open<close){
            generate(str+")",ans,open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("",ans,n,n);
        return ans;
    }
};