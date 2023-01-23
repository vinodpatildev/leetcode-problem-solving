class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trust_size = trust.size();
        unordered_map<int,int> umapf;
        unordered_map<int,int> umapt;
        if(n==1){
            return 1;
        }
        for(int i=0; i<trust_size; i++){
            umapf[trust[i][1]]++;
            umapt[trust[i][0]] = trust[i][1];
        }
        for(auto i:umapf){
            if(i.second == n-1 && umapt[i.first]==0){
                return i.first;
            }
        }
        return -1;
    }
};