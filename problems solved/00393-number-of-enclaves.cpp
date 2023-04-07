class Solution {
    int rows,cols;
    vector<int> delRow = {-1,+1,0,0};
    vector<int> delCol = {0,0,-1,+1};
    
    void dfs(vector<vector<int>>& mat, int row, int col){
        mat[row][col] = 0;
        for(int it=0; it<4; it++){
            int newRow = row + delRow[it];
            int newCol = col + delCol[it];
            if(newRow>=0 && newCol>=0 && newRow<rows && newCol<cols && mat[newRow][newCol]==1) dfs(mat,newRow,newCol);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> mat = grid;
        rows = grid.size();
        cols = grid[0].size();

        for(int it=0; it<rows; it++){
            if(mat[it][0]){
                // mat[it][0] = 0;
                dfs(mat,it,0);
            }
            if(mat[it][cols-1]){
                // mat[it][cols-1] = 0;
                dfs(mat,it,cols-1);
            }
        }
        for(int it=0; it<cols; it++){
            if(mat[0][it]){
                // mat[0][it] = 0;
                dfs(mat,0,it);
            }
            if(mat[rows-1][it]){
                // mat[rows-1][it] = 0;
                dfs(mat,rows-1,it);
            }
        }
        int count = 0;
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(mat[row][col]) count++;
            }
        }
        return count;
    }
};