class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int size = s.size(),i=0,len=0;
        vector<int> Max(size,-1);
        vector<int> Min(size,-1);
        unordered_map<char,int> map;
        Max[size-1] = size-1;
        map[s[size-1]] = size-1;
        for(i=size-2; i>=0; i--){
            if(map[s[i]]){
                Max[i] = map[s[i]];
            }else{
                Max[i] = i;
                map[s[i]] = i;
            }           
           
        }
        map.clear();
        Min[0] = 0;
        map[s[0]] = 0;
        for(i=1; i<size; i++){
            if(map[s[i]]){
                Min[i] = map[s[i]];
            }else{
                if(s[i]==s[0]){Min[i]=0;}
                else{Min[i] = i;}
                map[s[i]] = i;
            }            
        }
        for(i=1; i<size; i++){
            Max[i] = max(Max[i],Max[i-1]);
        }
        for(i=size-2; i>=0; i--){
            Min[i] = min(Min[i],Min[i+1]);
        }
        for(i=0; i<size-1; i++){
            if(Max[i]<Min[i+1]){
                ans.push_back(i+1-len);
                len = i+1;
            }
        }
        ans.push_back(i+1-len);
        return ans;
    }
};