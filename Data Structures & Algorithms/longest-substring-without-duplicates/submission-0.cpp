class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>s1;
        int l=0;
        int r=0;
        int len=0;
        while(r<s.size()){
            if(!s1.count(s[r])){
                
                s1.insert(s[r]);
                len=max(len,r-l+1);
                r++;}
            else {
                s1.erase(s[l]);
                l++;
            }
        }
        return len;
        
    }
};
