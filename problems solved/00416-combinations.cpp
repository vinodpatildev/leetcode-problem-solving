class Solution {
    void fun(int it, int n, int k, vector<int>& unit, vector<vector<int>>& res){
        if(unit.size() == k) { res.push_back(unit); return; }
        if(it == n) return;

        //not pick
        fun(it+1,n,k,unit,res);

        //pick
        unit.push_back(it+1);
        fun(it+1,n,k,unit,res);
        unit.pop_back();       
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> unit;
        fun(0,n,k,unit,res);
        return res;
    }
};