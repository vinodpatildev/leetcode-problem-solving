class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int& target) {
        int row=matrix.size(), col=matrix[0].size();
        int left=0, right=row*col;
        int mid;
        while(left<right){
            mid = (left+right)/2;
            if(matrix[mid/col][mid%col] < target) left = mid+1;
            else right = mid;
        }
        return left != row*col && matrix[left/col][left%col] == target;

    }
};