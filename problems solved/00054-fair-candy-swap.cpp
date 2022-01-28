class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice_total = 0;
        int bob_total = 0;
        vector<int> ans;
        unordered_map <int,int> map;
        for(int i=0; i<aliceSizes.size(); i++){
            alice_total += aliceSizes[i];
        }
        for(int i=0; i<bobSizes.size(); i++){
            bob_total += bobSizes[i];
            map[bobSizes[i]]++;
        }
        int diff = (bob_total - alice_total)/2;
        for(int i=0; i<aliceSizes.size(); i++){
            if(map[aliceSizes[i]+diff]){
                ans.push_back(aliceSizes[i]);
                ans.push_back(aliceSizes[i]+diff);
                return ans;
            }
        }
        return ans;
    }
};