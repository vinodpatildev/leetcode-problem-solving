class Solution {
public:
    void print_mat( vector<int> &map,vector<int> &leftDmap,vector<int> &rightDmap,vector<string> &mat){
        cout<<"[";
        for(int i=0; i<map.size(); i++){
            cout<<map[i]<<" ";
        }cout<<"]";cout<<endl;
        
        cout<<"[";
        for(int i=0; i<leftDmap.size(); i++){
            cout<<leftDmap[i]<<" ";
        }cout<<"]";cout<<endl;
        
        cout<<"[";
        for(int i=0; i<rightDmap.size(); i++){
            cout<<rightDmap[i]<<" ";
        }cout<<"]";cout<<endl;
        
        
        for(int i=0; i<mat.size(); i++){
            cout<<mat[i]<<endl;
        }
        cout<<"------------------------"<<endl;
    }
    
    void helper(vector<vector<string>> &ans, vector<string> &mat, vector<int> &map, vector<int> &leftDmap, vector<int> &rightDmap, int row, int n){
        if(row==n){
            ans.push_back(mat);
            return;
        }
        for(int col=0; col<n; col++){
            // cout<<"[row :"<<row<<", col:"<<col<<"]"<<endl;
            if(map[col]==0 && leftDmap[col-row +n-1]==0 && rightDmap[row+col]==0){
                // cout<<"[row :"<<row<<", col:"<<col<<"]"<<endl;
                map[col] = 1;
                leftDmap[col-row +n-1] = 1;
                rightDmap[row+col] = 1;
                mat[row][col] = 'Q';
                
                // print_mat(map,leftDmap,rightDmap,mat);                                                                                                       
                helper(ans,mat,map,leftDmap,rightDmap,row+1,n);
                
                map[col] = 0;
                leftDmap[col-row +n-1] = 0;
                rightDmap[row+col] = 0;
                mat[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> map(n,0);
        vector<int> rightDmap(2*n-1,0);
        vector<int> leftDmap(2*n-1,0);
        
        vector<string> mat;
        string s="";
        for(int i=0; i<n; i++){
            s += '.';
        }
        for(int i=0; i<n; i++){
            mat.push_back(s);
        }
        
        helper(ans,mat,map,leftDmap,rightDmap,0,n);
        return ans;
    }
};