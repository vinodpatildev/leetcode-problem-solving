class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> temp,st;
        for(int i=0; i<nums.size(); i++){
            if(temp.empty()){temp.push(nums[i]);}
            else if(nums[i] > temp.top()){
                temp.push(nums[i]);
            }
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty()){
                if(st.top() > nums[i]){
                    ans[i] = st.top();
                    break;
                }else{
                    st.pop();
                }
            }
            if(st.empty()){
                ans[i]=-1;
            }
            st.push(nums[i]);
        }
        return ans;
    }
};