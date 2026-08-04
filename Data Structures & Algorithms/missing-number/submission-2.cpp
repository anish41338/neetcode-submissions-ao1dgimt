class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            x^=i+1;
            ans^=nums[i];
        }
        return x^ans;
    }
};
