class Solution {
public:
    void generate(int index,vector<vector<int>>&ans,vector<int>&candidates,int target,vector<int>&cur){
        if(target==0){
            ans.push_back(cur);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            cur.push_back(candidates[i]);
            generate(i+1,ans,candidates,target-candidates[i],cur);
            cur.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>cur;
        generate(0,ans,candidates,target,cur);
        return ans;
    }
};
