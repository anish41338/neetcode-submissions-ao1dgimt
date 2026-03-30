class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mpp;
        for(auto str:strs){
            vector<int> v(26,0);
            for(auto it:str)v[it-'a']++;
            mpp[v].push_back(str);
        }
        for(auto it:mpp)ans.push_back(it.second);
        return ans;
        
    }
};
