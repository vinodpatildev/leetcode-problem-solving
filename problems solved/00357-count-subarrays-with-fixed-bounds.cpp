class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long res = 0, n = nums.size();
    for (int i = 0, j = 0; i <= n; ++i)
        if (i == n || nums[i] < minK || nums[i] > maxK)
            for (int p1 = j, p2 = j; j <= i; ++j) {
                while (p1 < i && (p1 < j || nums[p1] != minK))
                    ++p1;
                while (p2 < i && (p2 < j || nums[p2] != maxK))
                    ++p2;
                res += i - max(p1, p2);
            }
    return res;
}
};