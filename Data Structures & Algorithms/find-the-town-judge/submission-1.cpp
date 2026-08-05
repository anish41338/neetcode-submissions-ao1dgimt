class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>net(n+1,0);
        for(int i=0;i<trust.size();i++){
            net[trust[i][0]]-=1;
            net[trust[i][1]]+=1;
        }
        for(int i=1;i<=n;i++){
            if(net[i]==abs(n-1))return i;
        }
        return -1;
    }
};