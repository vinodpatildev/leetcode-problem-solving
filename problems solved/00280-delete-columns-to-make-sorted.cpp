class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int str_len = strs[0].size();
        set<int> columns;
        for(int i=0; i<str_len; i++) columns.insert(i);
        for(int i=1; i<strs.size(); i++){
            string str1 = strs[i-1];
            string str2 = strs[i];
            for(int col:columns) {
                if(str1[col] > str2[col]){
                    columns.erase(col);
                }
            }
        }
        return str_len - columns.size();
    }
};

// ["cba","daf","ghi"]
// ["zyx","wvu","tsr"]
// ["a","b"]