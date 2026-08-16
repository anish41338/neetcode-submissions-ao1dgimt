class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int l=0;
        int sum=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
             maxi=max(maxi,sum);
            if(sum<=0)sum=0;
           
        }
        return maxi;
    }
};
