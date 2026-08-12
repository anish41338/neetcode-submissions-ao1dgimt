class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    
    pq.push({0,{0,0}});
    set<pair<int,int>>vis;
    vector<int>dr={0,0,1,-1};
    vector<int>dc={1,-1,0,0};
    while(!pq.empty()){
        auto[diff,cord]=pq.top();
        pq.pop();
        if(vis.count(cord))continue;
        vis.insert(cord);
        if(cord.first==n-1 && cord.second==m-1)return diff;
        for(int i=0;i<4;i++){
            int newrow=cord.first+dr[i];
            int newcol=cord.second+dc[i];
            if(newrow<0 || newcol<0 ||newrow==n ||newcol==m ||vis.count({newrow,newcol}))continue;
            int newdiff=max(diff,abs(heights[newrow][newcol]-heights[cord.first][cord.second]));
            pq.push({newdiff,{newrow,newcol}});
        }

    }
    return 0;
    }
};