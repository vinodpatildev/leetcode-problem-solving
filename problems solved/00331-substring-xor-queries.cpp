class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map <long long, vector<int>> map;
        vector<vector<int>> ans;
        if(s[0]=='0') map[0] = {0,0};
        for(int start=0; start<s.size(); start++){
            long long num=0;
            if(s[start]=='0') {
                if(map.find(num) == map.end()) map[num] = {start,start};
                continue;
            }
            int start_end = start+32;
            int size = s.size();
            for(int end=start; end<min(start_end,size); end++){
                num *= 2;
                if(s[end]=='1'){
                    num += 1;
                }
                if(map.find(num) == map.end()) map[num] = {start,end};
            }
        }
        for(auto query : queries){
            int xor_val = query[0]^query[1];            
            if(map.find(xor_val) != map.end()){
                ans.push_back(map[xor_val]);
            }else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};