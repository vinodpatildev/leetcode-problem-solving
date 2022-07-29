class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        stack<pair<int,int>> st1,st2;
        int found = 0;
        int turn = 0;
        int minutes = -1;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    st1.push(make_pair(i,j));
                }
            }
        }
        
        while(!st1.empty() || !st2.empty()){
            if(turn==0){
                while(!st1.empty()){   
                    pair<int,int> current = st1.top(); st1.pop();
                    if(current.first>0 && grid[current.first-1][current.second]==1){
                        grid[current.first-1][current.second] = 2;
                        st2.push(make_pair(current.first-1,current.second));
                    }
                    if(current.first<m-1 && grid[current.first+1][current.second]==1){
                        grid[current.first+1][current.second] = 2;
                        st2.push(make_pair(current.first+1,current.second));
                    }
                    if(current.second>0 && grid[current.first][current.second-1]==1){
                        grid[current.first][current.second-1] = 2;
                        st2.push(make_pair(current.first,current.second-1));
                    }
                    if(current.second<n-1 && grid[current.first][current.second+1]==1){
                        grid[current.first][current.second+1] = 2;
                        st2.push(make_pair(current.first,current.second+1));
                    }
                }
            }else{
                while(!st2.empty()){
                    pair<int,int> current = st2.top(); st2.pop();
                    if(current.first>0 && grid[current.first-1][current.second]==1){
                        grid[current.first-1][current.second] = 2;
                        st1.push(make_pair(current.first-1,current.second));
                    }
                    if(current.first<m-1 && grid[current.first+1][current.second]==1){
                        grid[current.first+1][current.second] = 2;
                        st1.push(make_pair(current.first+1,current.second));
                    }
                    if(current.second>0 && grid[current.first][current.second-1]==1){
                        grid[current.first][current.second-1] = 2;
                        st1.push(make_pair(current.first,current.second-1));
                    }
                    if(current.second<n-1 && grid[current.first][current.second+1]==1){
                        grid[current.first][current.second+1] = 2;
                        st1.push(make_pair(current.first,current.second+1));
                    }
                }
            }
            turn = !turn;
            minutes++;
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        int allZeros=1;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0){
                    allZeros=0;
                    break;
                }
            }
            if(!allZeros){break;}
        }
        if(allZeros){return 0;}
        return minutes;
    }
};