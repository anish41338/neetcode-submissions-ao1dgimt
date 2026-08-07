class Solution {
public:
    int dfs(int i,vector<int>&dp,string &s){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return dp[i]=0;
        int res=dfs(i+1,dp,s);
        if(i+1<s.size() && ((s[i]=='1') || (s[i]=='2' && s[i+1]-'0'<7)))res+=dfs(i+2,dp,s);
        return dp[i]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return dfs(0,dp,s);
    }
};
