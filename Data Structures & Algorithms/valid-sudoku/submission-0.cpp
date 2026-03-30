class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool box[9][9]={},rows[9][9]={},columns[9][9]={};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int d=board[i][j]-'1';
                if(rows[i][d]||columns[j][d]||box[(i/3)*3+j/3][d])return false;
                rows[i][d]=columns[j][d]=box[(i/3)*3+j/3][d]=true;
            }
            
        }
        return true;
    }
};
