class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmax=1,curmin=1;
        int res=*max_element(nums.begin(),nums.end());
        for(auto it:nums){
            if(it==0){
                curmax=1;
                curmin=1;
                continue;
            }
            int temp=curmax*it;
            curmax=max(max(it*curmax,it),curmin*it);
            curmin=min(min(curmin*it,it),temp);
            res=max(res,curmax);
            
        }
        return res;
    }
};
