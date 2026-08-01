class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            if(mpp[it])return true;
            else mpp[it]++;
        }
        return false;
    }
};