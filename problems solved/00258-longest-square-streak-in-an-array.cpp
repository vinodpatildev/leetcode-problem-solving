class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int res=-1;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> emap,eimap;
        vector<int> smap(nums.size(),0);
        for(int i=nums.size()-1; i>=0; i--){
            long long sq = (long long)nums[i]*nums[i];
            if(sq<=INT_MAX && emap[(int)sq]) smap[i] = 1;
            emap[nums[i]]++;
            eimap[nums[i]] = i;
        }
        for(int i=0;i<smap.size(); i++){
            if(smap[i]){
                int index = i,len=0;
                while(index<smap.size()){
                    len++; 
                    if(smap[index]) smap[index]=0, index = eimap[nums[index]*nums[index]];
                    else break;
                }
                res = max(res,len);
            }
        }
        return res;
    }
};