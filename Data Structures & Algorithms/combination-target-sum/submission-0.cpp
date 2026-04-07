class Solution {
public:
    void generate(vector<vector<int>>&ans, vector<int>&nums,int target, vector<int>&cur,int index){
        if(target==0){
            ans.push_back(cur);
            return ;
        }
        if(target<0)return;
        for(int i=index;i<nums.size();i++){
            cur.push_back(nums[i]);
            generate(ans,nums,target-nums[i],cur,i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>cur;
        generate(ans,nums,target,cur,0);
        return ans;
    }
};
