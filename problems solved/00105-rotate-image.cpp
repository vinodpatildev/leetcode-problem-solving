class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size()/2; i++){
            for(int j=0; j<(matrix[0].size()+1)/2; j++){
                int temp = matrix[i][j];
                
                matrix[0+i][0+j] = matrix[matrix.size()-1-j][0+i];
                matrix[matrix.size()-1-j][0+i] = matrix[matrix.size()-1-i][matrix[0].size()-1-j];
                matrix[matrix.size()-1-i][matrix[0].size()-1-j] = matrix[0+j][matrix[0].size()-1-i];
                matrix[0+j][matrix[0].size()-1-i] = temp;
            }
        }
    }
};