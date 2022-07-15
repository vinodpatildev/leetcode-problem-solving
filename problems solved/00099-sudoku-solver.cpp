class Solution {
public:
    vector<int> hmask;
    vector<int> vmask;
    vector<vector<int>> matmask;
    
    Solution(){
        hmask.resize(9,0);
        vmask.resize(9,0);
        matmask.resize(3,vector<int>(3,0));
    }
    // string bin(int num){
    //     string s ="";
    //     while(num){
    //         if(num&1){
    //             s = "1"+s;
    //         }else{
    //             s = "0"+s;
    //         }
    //         num = num>>1;
    //     }
    //     return s;
    // }
    void init(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int shift = 1<<(board[i][j] - '1');
                    hmask[j] = hmask[j]|shift;
                    vmask[i] = vmask[i]|shift;
                    matmask[i/3][j/3] = matmask[i/3][j/3]|shift;
                }
            }
        }
//         cout<<"hmask :[";
//         for(int i=0; i<hmask.size(); i++){
//             cout<< bin(hmask[i]) <<" ";
//         }cout<<"]"<<endl;
//         cout<<"vmask :[";
//         for(int i=0; i<vmask.size(); i++){
//             cout<<bin(vmask[i])<<" ";
//         }cout<<"]"<<endl;
        
//         cout<<"matmask :\n[";
//         for(int i=0; i<matmask.size(); i++){
//             cout<<"[";
//             for(int j=0; j<matmask[0].size(); j++){
//                 cout<<bin(matmask[i][j])<<", ";
//             }cout<<"],"<<endl;
//         }cout<<"]"<<endl;
    }
    void setBit(int row,int col,int digit){
        int shift = 1<<(digit - 1);
        hmask[col] = hmask[col]|shift;
        vmask[row] = vmask[row]|shift;
        matmask[row/3][col/3] = matmask[row/3][col/3]|shift;
    }
    void unsetBit(int row,int col,int digit){
        int shift = 1<<(digit - 1);
        hmask[col] = hmask[col]^shift;
        vmask[row] = vmask[row]^shift;
        matmask[row/3][col/3] = matmask[row/3][col/3]^shift;
    }
    bool isSafe(int row,int col, int digit){
        unsigned int shift = 1<<(digit - 1);
        if(hmask[col] & shift){return false;}
        if(vmask[row] & shift){return false;}
        if(matmask[row/3][col/3] & shift){return false;}
        
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        if(row==9){ return true; }
        if(col==9){
            return helper(board,row+1,0);
        }
        if(board[row][col] == '.'){
                for(int digit=1; digit<=9; digit++){
                    if(isSafe(row,col,digit)){
                        board[row][col] = '0'+digit;
                        setBit(row,col,digit);
                        
                        if(helper(board,row,col+1)){return true;}
                        
                        board[row][col] = '.';
                        unsetBit(row,col,digit);               
                    }
                }
        }else{
            return helper(board,row,col+1);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        helper(board,0,0);
    }
};