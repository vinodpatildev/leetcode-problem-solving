class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int rxor=0,rxor2=0;
        for(int i=0; i<nums.size(); i++){
            rxor = rxor ^ nums[i];
        }
        cout<<"All XOR : "<<rxor<<endl;
        int pos=0, temp = rxor;
        while((temp&1)==0){
            temp = temp>>1;
            pos++;
        }
        cout<<"Pos    : "<<pos<<endl;
        int mask = 1<<pos;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&mask){
                rxor2 = rxor2 ^ nums[i];
            }
        }
        vector<int>ans;
        ans.push_back(rxor2);
        ans.push_back(rxor^rxor2);
        return ans;
    }
};