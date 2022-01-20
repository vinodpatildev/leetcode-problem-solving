class Solution {
public:
    string strAddition(string str1,string str2){
        string ans = "";
        char carry ='0';
        int i = str1.size()-1;
        int j = str2.size()-1;
        
        while(i>=0 && j>=0){
            ans = char(((str1[i]-'0') + (str2[j]-'0') + (carry-'0'))%10+'0') + ans;
            carry = char(((str1[i]-'0') + (str2[j]-'0') + (carry-'0'))/10+'0');
            i--;
            j--;
        }
        while(i>=0){
            ans = char(((str1[i]-'0') + (carry-'0'))%10+'0') + ans;
            carry = char(((str1[i]-'0') + (carry-'0'))/10+'0');
            i--;
        }
        while(j>=0){
            ans = char(((str2[j]-'0') + (carry-'0'))%10+'0') + ans;
            carry = char(((str2[j]-'0') + (carry-'0'))/10+'0');
            j--;
        }
        if(carry != '0'){
            ans = carry+ans;
        }
        return ans;
    }
    string multiplication(string str,char mul){
        int size = str.size();
        string ans = "";
        char carry='0';
        for(int i=size-1; i>=0; i--){
            ans = char(((str[i]-'0')*(mul-'0') + (carry-'0'))%10+'0') + ans;
            carry = char(((str[i]-'0')*(mul-'0') + (carry-'0'))/10+'0');
        }
        if(carry != '0'){
            ans = carry+ans;
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        string ans = "";
        int size1 = num1.size();
        int size2 = num2.size();
        string str1;
        string str2;
        if(size2>size1){
            str1 = num2;
            str2 = num1;
            size1 = num2.size();
            size2 = num1.size();
        }else{
            str1 = num1;
            str2 = num2;
        }
        cout<<"str1 :"<<str1<<endl;
        cout<<"str2 :"<<str2<<endl;
        cout<<"str1 :"<<size1<<endl;
        cout<<"str2 :"<<size2<<endl;
        if(size2==1 && str2=="0"){return "0";}
        for(int i=0; i<size2; i++){
            string temp="";
            char mul = str2[size2-1-i];
            temp = multiplication(str1,mul);
            for(int j=0; j<i; j++){
                temp += '0';
            }
            cout<<"--"<<temp<<"--"<<endl;
            ans = strAddition(temp,ans);              
        }
        return ans;
    }
};