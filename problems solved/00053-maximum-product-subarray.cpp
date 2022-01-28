class Solution {
public:
    int calculateMaxProduct(vector<int>&preProduct, vector<int>&next, vector<int>&prev,int left,int right){
        if(right==left){return preProduct[right+1]/preProduct[left];}
        if(right<left){return 0;}
        int product = preProduct[right+1]/preProduct[left];
        if(product<0){
            return max(calculateMaxProduct(preProduct,next,prev,next[left]+1,right), calculateMaxProduct(preProduct,next,prev,left,prev[right]-1));
        } 
        return product;
    }
    int maxProduct(vector<int>& nums) {
        vector<int> num;
        for(int i=0; i<nums.size(); i++){
            num.push_back(nums[i]);
        }
        int maxProduct = INT_MIN;
        vector<int> preProduct(nums.size()+1);
        vector<int> next(nums.size(),-1);
        vector<int> prev(nums.size(),-1);
        preProduct[0] = 1;
        for(int i=1; i<=nums.size(); i++){
            if(nums[i-1] != 0){
                preProduct[i] = preProduct[i-1]*nums[i-1];
            }else{
                preProduct[i] = 1;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]<0){
                next[i] = i;
            }else{
                next[i] = i+1< nums.size()? next[i+1]: -1;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                prev[i] = i;
            }else{
                prev[i] = i-1>= 0? prev[i-1]: -1;
            }
        }
        int left = 0;nums.push_back(0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                maxProduct = max(maxProduct,calculateMaxProduct(preProduct,next,prev,left,i-1));
                left = i+1;
                i++;
            }
        }
        if(maxProduct<0){
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i]==0){return 0;}
            }
        }
        return maxProduct;
    }
};