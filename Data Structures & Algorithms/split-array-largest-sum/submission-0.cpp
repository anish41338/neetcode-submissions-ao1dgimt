class Solution {
public:
    bool helper(vector<int>&nums,int k,int mid){
        int ans=1;
        int sum=0;
        for(auto it:nums){
            sum+=it;
            if(sum>mid){
                ans++;
                sum=it;
            }
        }
        return ans<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int r=accumulate(nums.begin(),nums.end(),0);
        int l=*max_element(nums.begin(),nums.end());
        int res=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(helper(nums,k,mid)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};