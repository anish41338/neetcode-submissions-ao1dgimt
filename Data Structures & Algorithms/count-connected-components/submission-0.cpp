class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,set<int>&vis){
        if(vis.count(node))return ;
        vis.insert(node);
        for(auto it:adj[node]){
            if(!vis.count(it))dfs(it,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        set<int>vis;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis.count(i)){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;

    }
};
