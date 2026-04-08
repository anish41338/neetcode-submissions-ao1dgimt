class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int index=-1;
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]>=target){
                index=i;
                break;
            }
        }
        if(index==-1)return false;
        for(int i=0;i<m;i++){
            if(matrix[index][i]==target)return true;
        }
        return false;
        
    }
};
