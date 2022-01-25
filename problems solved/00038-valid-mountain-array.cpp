class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        int slope = 1;
        int peak = 0;
        if(size<3){return false;}
        
        for(int i=0; i<size-1; i++){
            if(slope){
                if(arr[i]<arr[i+1]){continue;}
                else if(arr[i]==arr[i+1]){return false;}
                else{peak = i; slope = 0;}
            }
            if(slope==0){
                if(arr[i]>arr[i+1]){continue;}
                else{return false;}
            }
        }
        return peak==0?false:true;
    }
};