class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        map<int,int>hash;
        for(auto it:nums)hash[it]++;
        for(auto it:hash)if(it.second!=1)return it.first;
        return 0;
        
    }
};
