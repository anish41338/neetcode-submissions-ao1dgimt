class Solution {
public:
    void add(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&grid,queue<pair<int,int>>&q){
        if(i>=n||j>=m||i<0||j<0||vis[i][j]||grid[i][j]!=1)return;
        vis[i][j]=1;
        q.push({i,j});
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int time=-1;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto[r,c]=q.front();
                q.pop();
                grid[r][c]=2;
                
                add(r,c+1,n,m,vis,grid,q);
                add(r,c-1,n,m,vis,grid,q);
                add(r+1,c,n,m,vis,grid,q);
                add(r-1,c,n,m,vis,grid,q);
            }
            time++;

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return max(0,time);
    }
};
