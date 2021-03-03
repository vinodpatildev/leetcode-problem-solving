class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set <int> s;
        int counter = 0;
        int n = candyType.size();
            for(int i=0;i<n;i++){
                if(s.find(candyType[i]) == s.end()){
                    counter++;
                }
                s.insert(candyType[i]);
            }
        if(counter<(n/2)){
            return counter;
        }else{
            return n/2;
        }
    }
};