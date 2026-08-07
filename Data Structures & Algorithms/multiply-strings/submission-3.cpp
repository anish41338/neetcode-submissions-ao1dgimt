class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int>ans(n+m,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end()); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                ans[i+j+1]+=(ans[i+j]/10);
                ans[i+j]=ans[i+j]%10;
            }
        }
        reverse(ans.begin(),ans.end());
        int b=0;
        string res="";
        while(b<n+m && ans[b]==0 )b++;
        while(b<n+m)res+=to_string(ans[b++]);
        return res;
    }
};
