class Solution {
public:
    void generate(vector<vector<int>>&ans,vector<int>&nums,vector<int>&cur,vector<bool>&used){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])continue;
            used[i]=true;
            cur.push_back(nums[i]);
            generate(ans,nums,cur,used);
            cur.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        vector<bool>used(nums.size(),false);
        generate(ans,nums,cur,used);
        return ans;
        
    }
};
