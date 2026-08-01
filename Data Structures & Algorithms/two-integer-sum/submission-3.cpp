class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int r=target-nums[i];
            if(mpp.count(r)){
                return {min(mpp[r],i),max(mpp[r],i)};
            }
            else{
                mpp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};
