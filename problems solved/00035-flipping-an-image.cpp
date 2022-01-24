class Solution {
public:
    void iswap(int* p,int* q){
        int temp = *p;
        *p = !(*q);
        *q = !temp;
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans;
        int n = image.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<(n+1)/2; j++){
                iswap(&image[i][j],&image[i][n-1-j]);
                
            }
        }
        return image;
    }
};