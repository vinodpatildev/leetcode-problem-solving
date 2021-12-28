class Solution {
public:
    char returnChar(int i){
        if(i==0){
            return 'Z';
        }
        return 65+i-1;
    }
    string convertToTitle(int columnNumber) {
        string ans = "";
        if(columnNumber==26){
            return "Z";
        }
        if(columnNumber==0){
            return ans;
        }
        int curr = columnNumber%26;
        int prev = (curr==0)?(columnNumber/26)-1:columnNumber/26;
        
        cout<<"curr :"<<curr<<endl;
        cout<<"prev :"<<prev<<endl;
        cout<<"\n";
        
        ans = convertToTitle(prev)+returnChar(curr);        
        return ans;
    }
};