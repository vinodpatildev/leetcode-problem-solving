class Solution {
public:
    int tribonacci(int n) {
        vector<int> fibb(n+3);
        fibb[0] = 0;
        fibb[1] = 1;
        fibb[2] = 1;
        for(int i=3; i<=n; i++) fibb[i] = fibb[i-1] + fibb[i-2] + fibb[i-3];
        return fibb[n];        
    }
};