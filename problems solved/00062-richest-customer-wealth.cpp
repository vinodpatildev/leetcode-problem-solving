class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int col = accounts.size();
        int row = accounts[0].size();
        int max = INT_MIN,temp;
        
        for(int i=0; i<col; i++){
            for(int j=1; j<row; j++){
                accounts[i][j] += accounts[i][j-1];
            }
        }
        for(int i=0; i<col; i++){
            temp = accounts[i][row-1];
            cout<<temp<<" ,"<<endl;
            if(temp>max){max=temp;}
        }
        return max;
    }
};