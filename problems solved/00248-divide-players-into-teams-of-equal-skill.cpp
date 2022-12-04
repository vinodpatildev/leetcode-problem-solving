class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        long long sum = 0;
        sort(skill.begin(),skill.end());
        
        int left = 0,right = skill.size()-1;
        sum = skill[left] + skill[right];
        
        while(left < right){
            if(skill[left] + skill[right] != sum) return -1;
            ans += skill[left] * skill[right];
            left++; right--;
        }
        return ans;     
    }
};