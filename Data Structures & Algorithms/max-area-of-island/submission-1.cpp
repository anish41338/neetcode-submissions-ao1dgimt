class Solution {
public:
    int dfs(int i,int j, int n,int m,vector<vector<int>>&vis,vector<vector<int>>&grid){
        if(i>=n ||i<0||j<0||j>=m||vis[i][j]||grid[i][j]==0)return 0;
        vis[i][j]=1;
        return 1+dfs(i+1,j,n,m,vis,grid)+dfs(i-1,j,n,m,vis,grid)+dfs(i,j+1,n,m,vis,grid)+dfs(i,j-1,n,m,vis,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    maxi=max(maxi,dfs(i,j,n,m,vis,grid));
                }
            }
        }
        return maxi;
    }
};
