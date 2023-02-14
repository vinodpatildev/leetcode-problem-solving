class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        int size1 = a.size(), size2 = b.size();

        int size = min(size1,size2),it;
        for(it=0; it<size; it++){
            int val = (a[size1-1-it] - '0') + (b[size2-1-it] - '0') + carry;
            carry = val/2;
            val = val%2;
            ans = " " + ans;
            ans[0] = ('0'+val);
        }
        if(size1 > size2){
            for(it; it<size1; it++){
                int val = (a[size1-1-it] - '0') + carry;
                carry = val/2;
                val = val%2;
                ans = " " + ans;
                ans[0] = ('0'+val);
            }
        }else if(size1 < size2){
            for(it; it<size2; it++){
                int val = (b[size2-1-it] - '0') + carry;
                carry = val/2;
                val = val%2;
                ans = " " + ans;
                ans[0] = ('0'+val);
            }
        }
        if(carry){
            ans = " " + ans;
            ans[0] = ('0'+carry);
        }
        return ans;
    }
};