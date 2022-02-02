class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int size = arr.size(),i;
        if(size==1){return 1;}
        int ans=1;
        vector<int> leftMax(size); leftMax[0] = arr[0];
        vector<int> rightMin(size); rightMin[size-1] = arr[size-1]; 
        
        for(int i=1; i<size; i++){leftMax[i] = max(leftMax[i-1],arr[i]);}
        
        for(int i=size-2; i>=0; i--){rightMin[i] = min(rightMin[i+1],arr[i]);}
        
        for(int i=0; i<size-1; i++){if(leftMax[i]<=rightMin[i+1]){ans++;}} 
        return ans;
    }
};