class Solution {
public:
    void print_arr(vector<int> &nums){
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    bool helper(vector<int> &nums, int p){
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=p+1; i<nums.size(); i++){
            if(nums[i] > nums[p]){
                pq.push(nums[i]);
            }
        }
        if(!pq.empty()){
            int max = pq.top();
            for(int i=p+1; i<nums.size(); i++){
                if(nums[i]==max){
                    int temp = nums[i];
                    nums[i] = nums[p];
                    nums[p] = temp;
                    // reverse(&nums[p+1],&nums[nums.size()]);
                    sort(&nums[p+1],&nums[nums.size()]); 
                    return true;
                }
            }
        }
        return false;
    }
    void nextPermutation(vector<int>& nums) {
        
        for(int i=nums.size()-2; i>=0; i--){
            if(helper(nums,i)){
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};