class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minl=INT_MAX;
        int l=0;
        int sum=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
           // if(sum>=target)minl=min(minl,r-l+1);
            while(sum>=target){
                minl=min(minl,r-l+1);
                sum-=nums[l];
                l++;
                
            }
        }
        return minl==INT_MAX?0:minl;
    }
};