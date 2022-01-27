class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int column_size = grid.size();
        int row_size = grid[0].size();
        int i=column_size-1,j=0;
        int count = 0;
        while(i>=0 && j<row_size){
            if(grid[i][j]<0){
                i--;
            }else{
                count += (column_size-1-i)*(row_size-j);
                cout<<"count :"<<count<<endl;
                column_size = i+1;
                j++;
            }
        }
        count += (column_size-1-i)*(row_size-j);
        return count;
    }
};