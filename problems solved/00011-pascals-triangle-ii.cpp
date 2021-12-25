class Solution {
public:
    vector<int> getRow(int rowIndex) {        
        // nCr = ((n-r+1)/r)nCr-1
        
        int sizeVector = rowIndex+1;
        vector<int> ans(sizeVector);
        
        ans[0] = ans[sizeVector-1] = 1;
        for(int i=1; i<=(sizeVector-1)/2;i++){
            ans[i] = ans[sizeVector-1-i] = (int)(((double)(rowIndex-i+1)*((double)ans[i-1]))/i);
        }
        return ans;
    }
};