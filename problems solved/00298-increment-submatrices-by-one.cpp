class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        for(vector<int> query:queries){
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
            mat[row1][col1] += 1;
            if(col2+1<n) mat[row1][col2+1] -= 1;
            if(row2+1<n) mat[row2+1][col1] -= 1;
            if(row2+1<n && col2+1<n) mat[row2+1][col2+1] += 1;
        }
        for(int row=0; row<n; row++){
            for(int col=1; col<n; col++){
                mat[row][col] += mat[row][col-1];
            }
        }
        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                mat[row][col] += mat[row-1][col];
            }
        }
        return mat;
    }
};