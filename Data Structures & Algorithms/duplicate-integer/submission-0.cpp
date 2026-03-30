class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            if(mpp[it]!=0)return true;
            mpp[it]++;
        }
        return false;
        
    }
};