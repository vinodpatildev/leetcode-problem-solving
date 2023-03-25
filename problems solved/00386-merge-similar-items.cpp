class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map <int,int> mp;
        vector<vector<int>> res;
        for(int it=0; it<items1.size(); it++){
            mp[items1[it][0]] = items1[it][1];
        }
        for(int it=0; it<items2.size(); it++){
            res.push_back({ items2[it][0] , items2[it][1] + mp[items2[it][0]] });
            mp.erase(items2[it][0]);
        }
        for(auto p : mp){
            res.push_back({ p.first, p.second });
        }
        sort(res.begin(),res.end());
        return res;
    }
};