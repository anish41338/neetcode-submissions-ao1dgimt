class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(auto it:nums)mpp[it]++;
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>temp(n+1);
        for(auto it:mpp){
            temp[it.second].push_back(it.first);
        }
        for(int i=n;i>=1 && ans.size()<k ;i--){
            for(auto it:temp[i]){
                ans.push_back(it);
            if(ans.size()==k)break;}
        }
        return ans;
    }
};
