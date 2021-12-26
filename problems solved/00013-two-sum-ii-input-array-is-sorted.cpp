class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int size = numbers.size();
        int num;
        for(int i=0; i<size; i++){
            num = target - numbers[i];
            int l = 0, r = size-1;
            int mid;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(numbers[mid]==num){
                    if(i==mid){
                        if(mid+1&&numbers[mid+1]==num){
                            ans.push_back(i+1);
                            ans.push_back(mid+2);
                        }else if(mid-1&&numbers[mid-1]==num){
                            ans.push_back(i+1);
                            ans.push_back(mid);
                        }
                    }else{
                        ans.push_back(i+1);
                        ans.push_back(mid+1);
                    }
                    return ans;
                }else if(numbers[mid]<num){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return ans;
    }
};