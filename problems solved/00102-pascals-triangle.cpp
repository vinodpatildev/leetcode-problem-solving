class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            vector<int> row;
            row.push_back(1);
            if(i==1){ans.push_back(row); continue;}
            for(int j=1; j<i-1; j++){
                row.push_back(ans[i-2][j-1] + ans[i-2][j]);
            }
            row.push_back(1);
            ans.push_back(row);
            cout<<"[";
            for(int k=0; k<row.size(); k++){
                cout<<row[k]<<" ";
            }
            cout<<"]";
        }
        return ans;
    }
};