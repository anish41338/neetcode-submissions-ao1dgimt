class Solution {
public:
    int helper(int n){
        int cnt=0;
        while(n){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=helper(i);
        }
        return ans;
        
    }
};
