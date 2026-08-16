class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int far=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>far)return false;
            far=max(far,nums[i]+i);
          if(far>=n-1)return true;
        }
        return false;
    }
};
