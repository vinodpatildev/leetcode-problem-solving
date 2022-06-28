class Solution {
public:
    void print_arr(vector<int> &arr,int flag){
        
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        if(flag){cout<<"-------------------------------"<<endl;}
    }
    void helper(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &d, int index, int target){
        if(target==0){
            ans.push_back(d);
            print_arr(d,1);
            return;
        }
        if(index == candidates.size() ||  target < 0){
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i != index && candidates[i] == candidates[i-1]){continue;}
            
            d.push_back(candidates[i]);
            print_arr(d,0);
            helper(ans,candidates,d,i+1,target-candidates[i]);
            d.pop_back();
            
        }
        
//         helper(ans,candidates,d,index+1,target);
        
//         d.push_back(candidates[index]);
//         helper(ans,candidates,d,index+1,target-candidates[index]);
//         d.pop_back();
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> d;
        sort(candidates.begin(),candidates.end());
        helper(ans,candidates,d,0,target);
        return ans;
    }
};