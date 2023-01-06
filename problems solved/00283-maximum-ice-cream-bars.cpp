class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int icecreams = 0;
        while(icecreams < n && costs[icecreams] <= coins){
            coins -= costs[icecreams];
            icecreams++;
        }
        return icecreams;
    }
};

// 1 1 2 3 4