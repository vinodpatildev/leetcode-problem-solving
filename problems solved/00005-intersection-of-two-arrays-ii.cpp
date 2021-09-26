class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        
        vector<int> ans;
        
        for(int i=0; i<s1; i++){
            m1[nums1[i]]++;
        }
        for(int i=0; i<s2; i++){
            m2[nums2[i]]++;
        }
        
        for( auto i : m1){
            
            if(m2[i.first] > 0){
                int n = min(i.second,m2[i.first]);
                while(n--){
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};