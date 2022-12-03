class Solution {
public:
    string frequencySort(string s) {
        vector<int> mp(256,0);
        for(char c:s) mp[c]++;
        sort(s.begin(),s.end(), [&](char a, char b){ return mp[a]>mp[b] || (mp[a] == mp[b] && a < b);});
        return s;
    }
};