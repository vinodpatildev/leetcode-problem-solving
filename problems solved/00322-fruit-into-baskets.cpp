class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0, right=0, ans=0;
        unordered_map <int,int> mpp;
        while(right<fruits.size()){
            mpp[fruits[right]]++;
            if(mpp.size()>2){
                if(mpp[fruits[left]]==1){
                    mpp.erase(fruits[left]);
                }else{
                    mpp[fruits[left]]--;
                }
                left++;
            }else{
                ans = max(ans, right-left+1);
            }
            right++;
        }
        return ans;
    }
};