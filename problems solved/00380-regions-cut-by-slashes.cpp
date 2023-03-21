class Solution {
    void dfs(int r, int c, int n, vector<vector<bool>>& graph){
        if(graph[r][c]) return;
        graph[r][c] = true;
        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,-1,0,1};
        for(int del=0; del<4; del++){
            int nr = r + delr[del];
            int nc = c + delc[del];
            if(nr>=0 && nr<n && nc>=0 && nc<n && !graph[nr][nc]) dfs(nr,nc,n,graph);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int size = grid.size(), res = 0;
        vector<vector<bool>> graph(3*size,vector<bool>(3*size,false));
        for(int r=0; r<size; r++){
            for(int c=0; c<size; c++){
                if(grid[r][c]=='\\'){
                    graph[3*r][3*c] = true;
                    graph[3*r+1][3*c+1] = true;
                    graph[3*r+2][3*c+2] = true;
                }else if(grid[r][c]=='/'){
                    graph[3*r][3*c+2] = true;
                    graph[3*r+1][3*c+1] = true;
                    graph[3*r+2][3*c] = true;
                }
            }
        }
        int gsize = 3*size;
        for(int r=0; r<gsize; r++){
            for(int c=0; c<gsize; c++){
                if(!graph[r][c]){
                    res++;
                    dfs(r,c,gsize,graph);
                }
            }
        }        
        return res;
    }
};