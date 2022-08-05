class Solution {
public:
    void help(vector<int> &v, string &version){
        int i=0,j=-1;
        for(int m=0; m<version.size(); m++){
            if(version[m]=='.'){
                v.push_back(stoi(version.substr(i,j-i+1)));
                i=m+1;
                j=m-1;
            }
            j++;
        }
        v.push_back(stoi(version.substr(i,j-i+1)));
        
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        help(v1,version1);
        help(v2,version2);
        
        while(v1.size()<v2.size()){v1.push_back(0);}
        while(v2.size()<v1.size()){v2.push_back(0);}
        
        for(int i=0; i<v1.size(); i++){
            if(v1[i]<v2[i]){
                return -1;
            }else if(v1[i]>v2[i]){
                return 1;
            }
        }
        return 0;        
    }
};