class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>temp;
        for(auto it:intervals){
            if(temp.empty()||temp.back()[1]<=it[0]){
                temp.push_back(it);
            }
            else{
                if(temp.back()[1]>it[1]){
                    temp.back()=it;
                }
            }
        }
        return intervals.size()-temp.size();
        
    }
};
