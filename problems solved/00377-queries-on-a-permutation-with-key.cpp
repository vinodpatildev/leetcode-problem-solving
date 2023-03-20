class Solution {
    vector<int> bit;
    void add(int index, int val){
        while(index < bit.size()){
            bit[index] += val;
            index += index & (-index);
        }
    }
    int getSum(int index){
        int sum = 0;
        while(index > 0){
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        bit.resize(2*m+1,0);
        unordered_map <int,int> hmap;
        vector<int> res;
        for(int it=1; it<=m; it++){
            hmap[it] = m+it;
            add(m+it,1);
        }
        for(int q : queries){
            res.push_back(getSum(hmap[q])-1);
            add(hmap[q],-1);
            add(m,1);
            hmap[q] = m;
            m--;
        }
        return res;
    }
};