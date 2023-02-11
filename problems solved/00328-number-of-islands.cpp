class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0, rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> mat(rows, vector<int> (cols));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                mat[i][j] = grid[i][j] - '0';
            }
        }
        // for(int i=0; i<rows; i++){
        //     for(int j=0; j<cols; j++){
        //         cout<<mat[i][j]<<" ";
        //     }cout<<endl;
        // }
        
        queue<pair<int,int>> todo;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j]){
                    islands++;
                    todo.push({i,j});
                    mat[i][j] = 0;
                    while(!todo.empty()){
                        auto cell = todo.front(); todo.pop();
                        int row = cell.first, col = cell.second;

                        // if(row-1>=0 && col-1>=0 && mat[row-1][col-1]) mat[row-1][col-1] = 0, todo.push({row-1,col-1});
                        if(row-1>=0 && mat[row-1][col]) mat[row-1][col] = 0, todo.push({row-1,col});
                        // if(row-1>=0 && col+1<cols && mat[row-1][col+1]) mat[row-1][col+1] = 0, todo.push({row-1,col+1});
                        if(col-1>=0 && mat[row][col-1]) mat[row][col-1] = 0, todo.push({row,col-1});
                        if(col+1 < cols && mat[row][col+1]) mat[row][col+1] = 0, todo.push({row,col+1});
                        // if(row+1<rows && col-1>=0 && mat[row+1][col-1]) mat[row+1][col-1] = 0, todo.push({row+1,col-1});
                        if(row+1<rows && mat[row+1][col]) mat[row+1][col] = 0, todo.push({row+1,col});
                        // if(row+1<rows && col+1<cols && mat[row+1][col+1]) mat[row+1][col+1] = 0, todo.push({row+1,col+1});
                    }
                }
            }
        }
        return islands;        
    }
};