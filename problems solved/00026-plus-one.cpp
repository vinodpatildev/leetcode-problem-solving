class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 0;
        int temp;
        for(int i=digits.size()-1 ; i>=0; i--){
            carry = (digits[i]+1)/10;
            digits[i] = (digits[i]+1)%10;
            if(carry==0){break;}
        }
        
        if(carry==1){
            ans.push_back(1);
        }
        for(int i=0; i<digits.size(); i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};