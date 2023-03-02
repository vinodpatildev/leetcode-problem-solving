class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        char ch = chars[0];
        string output = "";
        for(int it=1; it<=chars.size(); it++){
            if(it == chars.size() || chars[it] != chars[it-1]){
                output += ch;
                if(count>1) {
                    output += to_string(count);
                }

                count=1;
                if(it!=chars.size()) ch = chars[it];
            }else{
                count++;
            }
        }
        for(int it=0; it<output.size(); it++) chars[it] = output[it];
        return output.size();
    }
};