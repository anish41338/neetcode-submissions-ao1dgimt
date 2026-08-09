class Solution {
public:
    set<int> dfs(int node,map<int,set<int>>&prereq,vector<vector<int>>&adj){
        if(prereq.count(node))return prereq[node];
            for(auto adjnodes:adj[node]){
            set<int>temp=dfs(adjnodes,prereq,adj);
            prereq[node].insert(temp.begin(),temp.end());
            prereq[node].insert(adjnodes);}
            return prereq[node];
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool>ans;
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        map<int,set<int>>prereq;
        for(int i=0;i<n;i++)dfs(i,prereq,adj);
        for(int i=0;i<queries.size();i++){
            ans.push_back(prereq[queries[i][0]].count(queries[i][1])>0);
        }
        return ans;

        
    }
};