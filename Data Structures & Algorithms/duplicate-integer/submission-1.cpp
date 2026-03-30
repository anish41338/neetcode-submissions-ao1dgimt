class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        for(auto n:nums)mpp[n]++;
        for(auto it:mpp)if(it.second>1)return true;
        return false;
        
    }
};