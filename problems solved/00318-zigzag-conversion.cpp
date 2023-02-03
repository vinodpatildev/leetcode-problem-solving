class Solution {
public:
    string convert(string s, int numRows) {
        int s_size = s.size();
        if(s_size==1){
            return s;
        }
        string ans = "";
        for(int i=0; i<numRows; i++){
            int j = 0;
            while(j<=s_size+numRows){
                if(i==0||i==numRows-1){
                    ans += (j+i<=s_size?s.substr(j+i,1):"");
                }else{
                    ans += j-i>=0&&j-i<=s_size?s.substr(j-i,1):"";
                    ans += j+i<=s_size?s.substr(j+i,1):"";
                }               
                j += numRows-1==0?1:2*(numRows-1);
            }
        }
        return ans;
    }
};