class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size(),-1);
        for(int col=0; col<grid[0].size(); col++){
            int i=0,j=col;
            while(i<grid.size()){
                if(grid[i][j]==1){
                    if(j==grid[0].size()-1 || grid[i][j+1]==-1){
                        break;
                    }
                    j++;

                }else if(grid[i][j]==-1){
                    if(j==0 || grid[i][j-1]==1){
                        break;
                    }
                    j--;
                }
                i++;
            }
            if(i==grid.size()){res[col]=j;}
        }
        return res;
    }
};