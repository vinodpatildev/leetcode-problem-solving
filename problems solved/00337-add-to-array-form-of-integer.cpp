class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int it=num.size()-1; it>=0 && k>0 ; it--){
            num[it] += k;
            k = num[it]/10;
            num[it] %= 10;
        }
        while(k>0){
            num.insert(num.begin(),k%10);
            k = k/10;
        }
        return num;
    }
};