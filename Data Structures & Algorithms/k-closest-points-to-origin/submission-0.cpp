class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {  vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>>pq;
        for(auto it:points){
            int dist=it[0]*it[0]+it[1]*it[1];
            pq.push({dist,it});
            while(pq.size()>k){
                pq.pop();
            }
            
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
