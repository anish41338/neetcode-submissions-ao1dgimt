class Solution {
public:
    int solve(vector<int>&nums,int l, int r){
        int rob1=nums[l];
        int rob2=max(nums[l],nums[l+1]);
        for(int i=l+2;i<=r;i++){
            int newrob=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=newrob;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        return max(solve(nums,0,nums.size()-2),solve(nums,1,nums.size()-1));
    }
};
