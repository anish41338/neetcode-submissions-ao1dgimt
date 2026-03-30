class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>freq;
        for(auto x:nums)freq[x]++;
        vector<vector<int>>bucket(nums.size()+1);
        for(auto it:freq)bucket[it.second].push_back(it.first);
        for(int i=bucket.size()-1;i>=0 && ans.size()<k;i--){
            for(int x:bucket[i]){
                ans.push_back(x);
                if(ans.size()==k)break;
            }
        }
        return ans;
        
    }
};
