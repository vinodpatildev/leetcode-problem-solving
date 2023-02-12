class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int root_color = image[sr][sc];
        int rows = image.size(), cols= image[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        vector<vector<int>> mat(rows,vector<int>(cols));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                mat[i][j] = image[i][j];
            }
        }
        queue<pair<int,int>> todo;
        todo.push({sr,sc});
        visited[sr][sc] = true;

        while(!todo.empty()){
            pair<int,int> cell = todo.front(); todo.pop();
            int i = cell.first, j = cell.second;
            mat[i][j] = color;

            if(i-1>=0 &&   visited[i-1][j] == false && mat[i-1][j] == root_color) visited[i-1][j] = true, todo.push({i-1,j});
            if(i+1<rows &&  visited[i+1][j] == false && mat[i+1][j] == root_color) visited[i+1][j] = true, todo.push({i+1,j});
            if(j-1>=0 &&  visited[i][j-1] == false && mat[i][j-1] == root_color) visited[i][j-1] = true, todo.push({i,j-1});
            if(j+1<cols &&  visited[i][j+1] == false && mat[i][j+1] == root_color) visited[i][j+1] = true, todo.push({i,j+1});
        }
        return mat;
    }
};