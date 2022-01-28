class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i]>0){
                for(int j=i+1; j<arr.size(); j++){
                    if(arr[j]==2*arr[i]){return true;}
                    else if(arr[j]>2*arr[i]){break;}
                }
            }else if(arr[i]<0){
                for(int j=i-1; j>=0; j--){
                    if(arr[j]==2*arr[i]){return true;}
                    else if(arr[j]<2*arr[i]){break;}
                }
            }else{
                if(i-1>=0 && arr[i-1]==arr[i]){return true;}
                if(i+1<arr.size() && arr[i]==arr[i+1]){return true;}
            }
            
        }
        return false;
    }
};