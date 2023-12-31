class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        for(int sal : salary) sum += sal;
        sum -= *min_element(salary.begin(),salary.end());
        sum -= *max_element(salary.begin(),salary.end());
        return sum/(salary.size()-2);
    }
};