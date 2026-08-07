class CountSquares {
public:
    map<pair<int,int>,int>mpp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mpp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res=0;
        int x=point[0];
        int y=point[1];
        for(auto it:mpp){
            int px=it.first.first;
            int py=it.first.second;
            if(abs(px-x)!=abs(py-y)||x==px||y==py)continue;
            res+=mpp[{x,py}]*mpp[{px,y}]*it.second;

        }
        return res;
    }
};
