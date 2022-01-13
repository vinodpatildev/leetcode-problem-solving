class Solution {
public:
    bool checkPerfect(int num){
        double root = sqrt(num);
        if(ceil(root) == floor(root)){
            return true;
        }
        return false;
    }
    int helper(vector<int>& arr,int arr_size,int k){
        if(k==arr_size){
            return 1;
        }
        int count = 0;
        unordered_map <int,int> map;
        int prev = k==0?0:arr[k-1];
        for(int i=k; i<arr_size; i++){
            if((checkPerfect(prev+arr[i]) || k==0) && !map[arr[i]]){
                map[arr[i]]++;
                swap(arr[k],arr[i]);
                count += helper(arr,arr_size,k+1);
                swap(arr[k],arr[i]);
            }
        }
        return count;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int arr_size = nums.size();
        if(arr_size==0 || arr_size==1){
            return 0;
        }
        return helper(nums,arr_size,0);        
    }
};