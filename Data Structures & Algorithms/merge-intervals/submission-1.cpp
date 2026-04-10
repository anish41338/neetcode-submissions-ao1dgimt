class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
             if(ans.back()[1]>=intervals[i][0]){
                int t1=ans.back()[0];
                int t2=ans.back()[1];
                ans.pop_back();
                ans.push_back({min(t1,intervals[i][0]),max(t2,intervals[i][1])});

            }
            else ans.push_back(intervals[i]);
        }}
        return ans;
    }
};
