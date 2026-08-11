class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            for(auto it:wordDict){
                if(i+it.size()<=s.size() && s.substr(i,it.size())==it){
                    dp[i]=dp[i+it.size()];
                }
                if(dp[i])break;
            }

        }
        return dp[0];
    }
};
