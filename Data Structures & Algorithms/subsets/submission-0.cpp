class Solution {
public:
    void generate(vector<vector<int>>&ans,vector<int>cur,vector<int>&nums,int index){
        if(nums.size()==index){
            ans.push_back(cur);
            return;
        }
       
            generate(ans,cur,nums,index+1);
            cur.push_back(nums[index]);
            generate(ans,cur,nums,index+1);
            cur.pop_back();

        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        generate(ans,cur,nums,0);
        return ans;
        
    }
};
