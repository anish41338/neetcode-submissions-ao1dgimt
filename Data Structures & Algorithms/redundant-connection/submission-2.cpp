class Solution {
public:
    int find(int n,vector<int>&par){
        if(n!=par[n])par[n]=find(par[n],par);
        return par[n];
    }
    bool unite(int n1,int n2,vector<int>&par,vector<int>&rank){
        int p1=find(n1,par);
        int p2=find(n2,par);
        if(p1==p2)return false;
        if(rank[p1]>rank[p2]){par[p2]=p1;rank[p1]+=rank[p2];}
        else {par[p1]=p2;rank[p2]+=rank[p1];}
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>par(n+1);
        for(int i=0;i<n+1;i++)par[i]=i;
        vector<int>rank(n+1,1);
        for(auto it:edges){
            if(!unite(it[0],it[1],par,rank))return {it[0],it[1]};
        }
        return {-1,-1};
    }
};
