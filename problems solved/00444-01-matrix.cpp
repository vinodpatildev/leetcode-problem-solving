class Solution {
    // void dfs(int dist, const vector<vector<int>>& mat, vector<vector<int>>& res, int i, int j, const int&m, const int& n){
    //     if(dist>=res[i][j]) return;
    //     res[i][j] = dist;
    //     for(int it=0; it<4; it++){
    //         int ic = i+deli[it];
    //         int jc = j+delj[it];
    //         if(ic>=0 && ic<m && jc>=0 && jc<n && res[ic][jc] && dist+1 < res[ic][jc]) dfs(dist+1, mat, res, ic, jc, m, n);
    //     }
    // }
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> del = {0, 1, 0, -1, 0};
        vector<vector<int>> res(m,vector<int>(n));
        queue<pair<int,int>> todo;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) {res[i][j] = 0; todo.push({i,j});}
                else res[i][j] = -1;
            }
        }

        while(!todo.empty()){
           auto [id, jd] = todo.front(); todo.pop();
            for(int it=0; it<4; it++){
                int ic = id+del[it];
                int jc = jd+del[it+1];
                if(ic>=0 && ic<m && jc>=0 && jc<n && res[ic][jc] == -1) {
                    res[ic][jc] = res[id][jd]+1;
                    todo.push({ic,jc});
                }
            }
        }
        return res;
    }
};