class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,total=0,fuel=0;
        for(int i=0; i<gas.size(); i++) {
            fuel = fuel + gas[i] - cost[i];
            if(fuel < 0){
                start = i+1;
                total += fuel;
                fuel = 0;
            }
        }
        return fuel + total < 0? -1 : start;
    }
};