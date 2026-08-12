class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][n-1]==target)return true;
            else if(matrix[mid][n-1]>target)high=mid-1;
            else low=mid+1;
        }
        if(low>=m)return false;
        int i=0;
        n--;
        while(i<=n){
            int mid=(i+n)/2;
            if(matrix[low][mid]==target)return true;
            else if(matrix[low][mid]>target)n=mid-1;
            else i=mid+1;
        }
        return false;
    }
};
