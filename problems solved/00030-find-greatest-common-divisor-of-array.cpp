class Solution {
public:
    int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
    int findGCD(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());
        return gcd(max,min);
    }
};