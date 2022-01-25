class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> range(right-left+2,0);
        int l,r;
        for(int i=0; i<ranges.size(); i++){
            l = ranges[i][0];
            r = ranges[i][1];
            
            if(l<=right && r>=left){
                range[max(l,left)-left] += 1;
            }
            if(r>=left && l<=right){
                range[min(r,right)-left+1] -= 1;
            }
        }
        for(int i=0; i<range.size(); i++){
            cout<<range[i]<<" ";
        }cout<<endl;
        int par = 0;
        for(int i=0; i<range.size(); i++){
            par += range[i];
            range[i] = par;
        }
        for(int i=0; i<range.size(); i++){
            cout<<range[i]<<" ";
        }cout<<endl;
        for(int i=0; i<range.size()-1; i++){
            if(range[i]==0){return false;}
        }
        return true;
    }
};