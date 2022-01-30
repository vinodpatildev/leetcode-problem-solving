class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0,i,j,size = heights.size(),temp;
        vector<int> left(size);
        vector<int> right(size);
        stack<int> st;
        st.push(0);
        for(i=1; i<size; i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
                right[st.top()] = size;
                st.pop();
        }  
        st.push(size-1);
        for(i=size-2; i>=0; i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
                left[st.top()] = -1;
                st.pop();
        }
        for(i=0; i<size; i++){
            temp = (right[i]-left[i]-1)*heights[i];
            if(temp>max_area){
                max_area = temp;
            }
        }
        return max_area;
    }
};