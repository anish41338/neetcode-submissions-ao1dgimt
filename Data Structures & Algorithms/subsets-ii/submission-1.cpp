class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int index){
        ans.push_back(cur);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])continue;
            cur.push_back(nums[i]);
            generate(ans,cur,nums,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
        vector<int> cur;
        generate(ans, cur, nums, 0);
        return ans;
    }
};
