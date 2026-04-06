class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>points;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)points.push_back({i,j});
            }
        }
        set<int>rows;
        set<int>cols;
        for(auto x:points){
            rows.insert(x.first);
            cols.insert(x.second);
        }
        for(auto x:rows){
            for(int i=0;i<matrix[0].size();i++){
            matrix[x][i]=0;
        }
        }
        for(auto x:cols){
            for(int j=0;j<matrix.size();j++){
                matrix[j][x]=0;
            }
        }
        
    }
};
