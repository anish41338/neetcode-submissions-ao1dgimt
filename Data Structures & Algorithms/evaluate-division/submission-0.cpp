class Solution {
public:
    double bfs(string a,string b,map<string,vector<pair<string,double>>>&mpp){
        if(!mpp.count(a) ||!mpp.count(b))return -1;
        queue<pair<string,double>>q;
        q.push({a,1});
        set<string>vis;
        vis.insert(a);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string node=q.front().first;
                double val=q.front().second;
                q.pop();
                if(node==b)return val;
                for(auto it:mpp[node]){
                    if(!vis.count(it.first)){
                        q.push({it.first,it.second*val});
                        vis.insert(it.first);

                    }
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        map<string,vector<pair<string,double>>>mpp;
        for(int i=0;i<values.size();i++){
            mpp[equations[i][0]].push_back({equations[i][1],values[i]});
              mpp[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
     
        for(int i=0;i<queries.size();i++){
            string a=queries[i][0];
            string b=queries[i][1];
            ans.push_back(bfs(a,b,mpp));
        }
        return ans;



    }
};