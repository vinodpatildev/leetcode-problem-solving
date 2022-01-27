class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int,int>> soldier_count(mat.size());
        int col_size = mat.size(),row_size = mat[0].size(),i,j;
        for(i=0; i<col_size; i++){
            for(j=0; j<row_size; j++){
                if(mat[i][j] != 1){
                    soldier_count[i] = make_pair(j,i);
                    break;
                }
            }
            if(j==row_size){soldier_count[i] = make_pair(j,i);}
        }
        sort(soldier_count.begin(), soldier_count.end());
        for(int i=0; i<k; i++){
            ans.push_back(soldier_count[i].second);
        }
        return ans;
    }
};