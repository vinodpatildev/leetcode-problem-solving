class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max = INT_MIN;
        int temp;
        for(int i=0; i<rectangles.size(); i++){
            int temp = min(rectangles[i][0],rectangles[i][1]);
            if( temp > max){
                max = temp;
            }
        }
        int count=0;
        for(int i=0; i<rectangles.size(); i++){
            int temp = min(rectangles[i][0],rectangles[i][1]);
            if( temp == max){
                count++;
            }
        }
        return count;
    }
};