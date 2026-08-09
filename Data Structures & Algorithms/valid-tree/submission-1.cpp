class Solution {
public:
    bool dfs(int node,set<int>&st,vector<vector<int>>&ans,int prev){
        if(st.count(node))return false;
        st.insert(node);
        for(auto adj:ans[node]){
            if(adj==prev)continue;
            if(!dfs(adj,st,ans,node))return false;
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==0)return true;
        vector<vector<int>>ans(n);
        for(auto it:edges){
            ans[it[0]].push_back(it[1]);
            ans[it[1]].push_back(it[0]);}
        set<int>st;
        return dfs(0,st,ans,-1)&&(st.size()==n);
        
    }
};
