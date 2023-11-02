class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat[0].size(),sum=0;
        int left = 0,right = n-1;
        for(int i=0; i<n; i++){
            if(left==right){
                sum += mat[i][left];
            }else{
                sum += (mat[i][left]+mat[i][right]);
            }
            left++;right--;
        }
        return sum;
    }
};