class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes=0;
        int n=nums.size();
        int ones=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zeroes++;
            else if(nums[i]==1)ones++;
        }
        for(int i=0;i<zeroes;i++)nums[i]=0;
        for(int i=zeroes;i<zeroes+ones;i++)nums[i]=1;
        for(int i=zeroes+ones;i<n;i++)nums[i]=2;
        
    }
};