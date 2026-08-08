class Solution {
public:
    bool dfs(int node,map<int,set<int>>&mpp,set<int>&vis){
        if(vis.count(node))return false;
        if(mpp[node].empty())return true;
        vis.insert(node);
        for(auto adj:mpp[node]){
            if(!dfs(adj,mpp,vis))return false;
        }
        vis.erase(node);
        mpp[node]={};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        map<int,set<int>>mpp;
        for(auto it:prerequisites)mpp[it[0]].insert(it[1]);
        set<int>vis;
        for(int i=0;i<n;i++){if(!dfs(i,mpp,vis))return false;}
        return true;
    }
};
