class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        map<int,set<int>>adj;
        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        map<int,int>edges1;
        queue<int>leaves;
        for (int i=0;i<n;i++){
            if(adj[i].size()==1)leaves.push(i);
            edges1[i]=adj[i].size();
        }
        while(!leaves.empty()){
            if(n<=2) break;
            int sz=leaves.size();
            while(sz--){
                int node=leaves.front();
                leaves.pop();
                n--;
                for(auto it:adj[node]){
                    edges1[it]--;
                    if(edges1[it]==1)leaves.push(it);
                }
            }
        }
        vector<int>ans;
        while(!leaves.empty()){ans.push_back(leaves.front());
        leaves.pop();}
        return ans;
        
    }
};