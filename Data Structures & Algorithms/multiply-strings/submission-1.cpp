class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        //int carry=0;
        vector<int>result(m+n,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=mul+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;


            }
        }
        string ans="";
        for(auto x:result){
            if(!(ans.empty() && x==0)){
            ans+=to_string(x);}
        }
        return ans.empty()?"0":ans;
        
    }
};
