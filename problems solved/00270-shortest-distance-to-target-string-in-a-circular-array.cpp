class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int size = words.size(),res = -1;
        int distLeft = INT_MAX, distRight = INT_MAX;
        for(int i=0; i<size; i++){
            if(words[(startIndex - i + size)%size]==target){ distLeft = i; break; }
        }
        for(int i=0; i<size; i++){
            if(words[(startIndex + i)%size]==target){ distRight = i; break; }
        }
        if(distLeft != INT_MAX && distRight != INT_MAX) res = min(distLeft,distRight);
        return res;
    }
};