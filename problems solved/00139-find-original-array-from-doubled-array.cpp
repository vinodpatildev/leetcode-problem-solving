class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2==1){vector<int> ans;return ans;}
        unordered_map <int,int> map;
        vector<int> ans_arr;
        sort(changed.begin(),changed.end());
        for(int i=0; i<changed.size(); i++){
            map[changed[i]]++;
        }
        for(int i=changed.size()-1; i>=0; i--){
            if(map[changed[i]] && (changed[i]%2==0) && map[changed[i]/2]){
                ans_arr.push_back(changed[i]/2);
                map[changed[i]]--;
                map[changed[i]/2]--;
            }
        }
        for(auto x:map){
            if(x.second){
                vector<int> ans;
                return ans;
            }
        }
        
        reverse(ans_arr.begin(), ans_arr.end());
        return ans_arr;       
    }
};