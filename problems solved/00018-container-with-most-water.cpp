class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIndex = 0;
        int rightIndex = height.size()-1;
        int maxWater = 0;
        
        while(leftIndex<rightIndex){
            int water = (rightIndex-leftIndex)*min(height[leftIndex],height[rightIndex]);
            if(water > maxWater){
                maxWater = water;
            }if(height[leftIndex] <= height[rightIndex]){
                leftIndex++;
            }else{
                rightIndex--;
            }           
        }
        return maxWater;
    }
};