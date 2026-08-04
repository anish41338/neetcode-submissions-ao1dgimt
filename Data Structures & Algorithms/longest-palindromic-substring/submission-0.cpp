class Solution {
public:
    string longestPalindrome(string s) {
        int reslen=0;
        string res="";
        for(int i=0;i<s.size();i++){
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if((r-l+1)>reslen){
                    reslen=r-l+1;
                    res=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            int l1=i;
            int r1=i+1;
            while(l1>=0 &&r1<s.size() && s[l1]==s[r1]){
                if((r1-l1+1)>reslen){
                    reslen=r1-l1+1;
                    res=s.substr(l1,r1-l1+1);
                }
                l1--;
                r1++;
            }
        }
        return res;
    }
};
