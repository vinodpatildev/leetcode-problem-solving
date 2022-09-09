class Solution {
public:
    static bool sorter(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(),sorter);
        int minUN = INT_MIN;
        int count = 0;        
        // for(int i=0; i<properties.size(); i++){
        //     cout<<"[";
        //     for(int j=0; j<properties[i].size(); j++){
        //         cout<<properties[i][j]<<",";
        //     }
        //     cout<<"],";
        // }
        for(int i=properties.size()-1; i>=0; i--){
            if(properties[i][1] < minUN){
                count++;
            }else{
                minUN = properties[i][1];
            }
        }
        return count;                         
    }
};