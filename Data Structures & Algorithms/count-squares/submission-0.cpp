class CountSquares {
public:
    map<pair<int,int>,int>mpp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mpp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        for(auto &[p,f]:mpp){
            int px=p.first;
            int py=p.second;
            if(abs(x-px)!=abs(y-py) || x==px)continue;
            ans+=f*mpp[{x,py}]*mpp[{px,y}];

        }
        return ans;
        
    }
};
