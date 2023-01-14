class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> char_groups(26,0);
        unordered_map <int,char> group_min_char_map;
        string res="";
        for(int i=0; i<s1.size(); i++){
            if(char_groups[s1[i]-'a'] == 0 && char_groups[s2[i]-'a'] == 0) {
                char_groups[s1[i]-'a'] = i+1;
                char_groups[s2[i]-'a'] = i+1;
            }else if(char_groups[s1[i]-'a'] && char_groups[s2[i]-'a']) {
                if(char_groups[s1[i]-'a'] != char_groups[s2[i]-'a']){
                    int group = min(char_groups[s1[i]-'a'],char_groups[s2[i]-'a']);
                    int converted_group = max(char_groups[s1[i]-'a'],char_groups[s2[i]-'a']);
                    for(int it=0; it<26; it++) {
                        if(char_groups[it]==converted_group) char_groups[it] = group;
                    }
                }
            }else if(char_groups[s1[i]-'a'] > 0){
                char_groups[s2[i]-'a'] = char_groups[s1[i]-'a'];
            }
            else if(char_groups[s2[i]-'a'] > 0){
                char_groups[s1[i]-'a'] = char_groups[s2[i]-'a'];
            }
        }
        cout<<"[";
        for(int it=0; it<char_groups.size(); it++){
            cout<<char('a'+it)<<", ";
        }cout<<"]"<<endl;
        cout<<"[";
        for(int it=0; it<char_groups.size(); it++){
            cout<<char_groups[it]<<", ";
        }cout<<"]"<<endl;

        for(int it=0; it<char_groups.size(); it++){
            if(char_groups[it]) {
                if(group_min_char_map.find(char_groups[it]) == group_min_char_map.end()){
                    group_min_char_map[char_groups[it]] = char('a'+it);
                }
                else{
                    group_min_char_map[char_groups[it]] = min(group_min_char_map[char_groups[it]],char('a'+it));
                }
            }
        }
        for(char ch:baseStr){
            if(group_min_char_map.find(char_groups[ch-'a']) != group_min_char_map.end() ){
                res += group_min_char_map[char_groups[ch-'a']];
            }else{
                res += ch;
            }
            
        }
        return res;
    }
};