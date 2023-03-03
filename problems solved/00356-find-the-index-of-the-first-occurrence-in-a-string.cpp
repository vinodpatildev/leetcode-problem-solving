class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_size = haystack.size();
        int need_size = needle.size();
        if(need_size == 0){
            return 0;
        }
        for(int i=0; i<hay_size; i++){
            if(haystack[i] == needle[0]){
                int OccuranceBit = 1;
                for(int j = i ; j < i + need_size; j++){
                    if(haystack[j] != needle[j-i]){
                        OccuranceBit = 0;
                        break;
                    }
                }
                if(OccuranceBit == 1){
                    return i;
                }
            }
        }
        return -1;
    }
};