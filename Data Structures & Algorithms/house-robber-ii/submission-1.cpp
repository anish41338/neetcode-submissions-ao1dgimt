class Solution {
public:
    int solve(vector<int>&nums, int l,int r){
        int prev1=0;
        int prev2=0;
        for(int i=l;i<=r;i++){
            int cur=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int l1=solve(nums,0,n-2);
        int l2=solve(nums,1,n-1);
        return max(l1,l2);
        
    }
};
