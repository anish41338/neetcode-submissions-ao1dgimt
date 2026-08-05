class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        prefix.assign(rows+1,vector<int>(cols+1,0));
        for(int r=0;r<rows;r++){
            int rowsum=0;
            for(int c=0;c<cols;c++){
                rowsum+=matrix[r][c];
                int above=prefix[r][c+1];
                prefix[r+1][c+1]=rowsum+above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        int left=prefix[row2][col1-1];
        int above=prefix[row1-1][col2];
        int given=prefix[row2][col2];
        int leftsum=prefix[row1-1][col1-1];
        return given-left-above+leftsum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */