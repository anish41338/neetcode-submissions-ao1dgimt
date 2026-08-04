class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res="";
        int carry=0;
        for(int i=0;i<max(a.size(),b.size());i++){
            int digitA=i<a.size()?(a[i]-'0'):0;
            int digitB=i<b.size()?(b[i]-'0'):0;
            int result=digitA+digitB+carry;
            carry=result/2;
            res=to_string(result%2)+res;

        }
        if(carry)res=to_string(carry)+res;
        return res;
    }
};