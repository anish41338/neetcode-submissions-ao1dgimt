class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int curend=0;
        int far=0;
        for(auto i=0;i<nums.size();i++){
            far=max(far,nums[i]+i);
            if(i==nums.size()-1)return jumps;
            if(i==curend){
                jumps++;
                curend=far;
            }
        }
        return jumps;
    }
};
