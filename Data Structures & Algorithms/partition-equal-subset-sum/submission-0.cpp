class Solution {
public:
    bool can(vector<int>&nums,int idx,int sum ,int target){
        if(sum==target)return true;
        if(idx==nums.size())return false;
        return can(nums,idx+1,sum+nums[idx],target)||can(nums,idx+1,sum,target);

    }
    bool canPartition(vector<int>& nums) {
        
       int sum=0;
       for(auto it:nums)sum+=it;
       if(sum%2!=0)return false;
       return can(nums,0,0,sum/2); 
    }
};
