class Solution {
public:
    bool dfs(int node,set<int>&vis,set<int>&cycle,map<int,set<int>>&mpp,vector<int>&ans){
        if(cycle.count(node))return false;
        if(vis.count(node))return true;
        cycle.insert(node);
        for(auto adj:mpp[node]){
            if(!dfs(adj,vis,cycle,mpp,ans))return false;
        }
        cycle.erase(node);
        vis.insert(node);
        ans.push_back(node);
        return true;
         
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        map<int,set<int>>mpp;
        set<int>vis;
        for(auto it:prerequisites)mpp[it[0]].insert(it[1]);
        vector<int>ans;
       
        set<int>cycle;
        for(int i=0;i<n;i++){
            if(!dfs(i,vis,cycle,mpp,ans))return {};
        }
        return ans;

    }
};
