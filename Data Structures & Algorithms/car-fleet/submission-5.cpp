class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,int>>v;
        for(int i=0;i<speed.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),[](auto&a,auto&b){
            return a.first>b.first;
        });
        for(auto it:v){
           double time=(double)(target-it.first)/it.second;
           if(st.empty()||st.top()<time){
            st.push(time);
           }
        }
        return st.size();

    }
};
