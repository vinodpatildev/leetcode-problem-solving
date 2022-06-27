class Solution {
public:
    void print_arr(vector<int> &arr,int space){
        cout<<"-------------------------------"<<endl;
        while(space--){cout<<" ";}
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds, int index){
        ans.push_back(ds);
        // print_arr(ds,index);
        
        for(int i=index; i<nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]){continue;}
            
            ds.push_back(nums[i]);
            helper(ans,nums,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(ans,nums,ds,0);
        return ans;
    }
};