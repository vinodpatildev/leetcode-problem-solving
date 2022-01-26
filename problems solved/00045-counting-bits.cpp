class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int temp,tempCount;
        for(int i=0; i<=n; i++){
            temp = i;
            while(temp){
                ans[i] += (temp&1);
                temp = temp>>1;
            }
            cout<<ans[i]<<" ";
        }
        return ans;
    }
};