class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0,size1 = arr1.size(), size2 = arr2.size(),i,j;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        
        for(i=0; i<size1; i++){
            j=0;
            while(j<size2){
                if(abs(arr1[i]-arr2[j]) <= d){
                    j=INT_MAX;
                    break;
                }
                j++;
            }
            if(j==INT_MAX){continue;}
            count++;
        }
        return count;
    }
};