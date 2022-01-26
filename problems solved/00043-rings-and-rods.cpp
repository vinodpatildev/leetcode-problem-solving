class Solution {
public:
    int countPoints(string rings) {
        set<int> red;
        set<int> green;
        set<int> blue;
        for(int i=0; i<rings.size(); i = i+2){
            if(rings[i]=='R'){red.insert(rings[i+1]-'0');}
            else if(rings[i]=='G'){green.insert(rings[i+1]-'0');}
            else if(rings[i]=='B'){blue.insert(rings[i+1]-'0');}
        }
        vector<int> flag(10,0);
        int count = 0;
        set<int>::iterator itr;
        for (itr = red.begin(); itr != red.end(); itr++) {
            flag[*itr]++;
        }
        for (itr = green.begin(); itr != green.end(); itr++) {
            flag[*itr]++;
        }
        for (itr = blue.begin(); itr != blue.end(); itr++) {
            flag[*itr]++;
        }
        for (int i=0; i<flag.size();i++) {
            if(flag[i]==3){count++;}
        }
        return count;
    }
};