class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int res = 0;
        unordered_map<int,int> task_map;

        for(int element : tasks) task_map[element]++;
        for(pair<int,int> mapping : task_map){
            if(mapping.second == 1) return -1;
            res += mapping.second/3;
            if(mapping.second%3 != 0) res++;
        }
        return res;
    }
};


// 2 2 2 3 3 4 4 4 4 4