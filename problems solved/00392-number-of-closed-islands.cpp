class Solution {
    vector<int> delRow = {-1,1,0,0};
    vector<int> delCol = {0,0,-1,1};
    int rows,cols;
    void dfs(vector<vector<int>>& mat, int row,int col){
        mat[row][col] = 1;

        for(int it=0; it<4; it++){
            int newRow = row+delRow[it];
            int newCol = col+delCol[it];

            if(newRow >= 0 && newRow<rows && newCol >= 0 && newCol<cols && mat[newRow][newCol] == 0){
                dfs(mat, newRow, newCol);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        vector<vector<int>> mat = grid;
        rows = grid.size();
        cols = grid[0].size();

        for(int it=0; it<cols; it++){
            if(mat[0][it] == 0) dfs(mat, 0, it);
            if(mat[rows-1][it] == 0) dfs(mat, rows-1,it);
        }
        for(int it=0; it<rows; it++){
            if(mat[it][0] == 0) dfs(mat, it, 0);
            if(mat[it][cols-1] == 0) dfs(mat, it, cols-1);
        }

        for(int row=1; row<rows-1; row++){
            for(int col=1; col<cols-1; col++){
                if(mat[row][col]==0){
                    count++;
                    mat[row][col] = 1;
                    dfs(mat,row,col);
                }
            }
        }
        return count;
    }
};