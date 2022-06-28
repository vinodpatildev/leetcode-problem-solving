class Solution {
private:
    
public:
    vector<int> fact;

    void init(int n){
        for(int i=0; i<=n; i++){
            fact.push_back(i);
        }
        fact[0] = 1;
        for(int i=2; i<=n; i++){
            fact[i] = fact[i] * fact[i-1];
        }
        cout<<"[";
        for(int i=0; i<=n; i++){
            cout<<fact[i]<<" ";
        }
        cout<<"]";        
    }
    string permute(vector<int> &digits, string &s, int base, int index, int n, int k){
        if(digits.size()==0){
            return s;
        }
        int left = base;
        int right = base;
        int interval_size = fact[digits.size()-1];
        for(int i=0; i<digits.size(); i++){
            left = right;
            right = base + (i+1)*interval_size;
            
            if(k>=left && k<right){
                s += digits[i];
                digits.erase(digits.begin()+i);
                return permute(digits,s,left,index,n-1,k);
            }
        }
        return s;
    }
    string getPermutation(int n, int k) {
        vector<int> digits;
        string s;
        for(int i=1; i<=n; i++){
            digits.push_back('0'+i);
        }
        init(n);
        return permute(digits, s, 0, 0, n, k-1);
    }
};