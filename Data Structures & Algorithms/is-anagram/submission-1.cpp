class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        if(s.length()!=t.length())return false;
        for(auto ch:s){
            mpp[ch]++;
        }
        for(auto ch:t)mpp[ch]--;
        for(auto it:mpp)if(it.second!=0)return false;
        return true;
        
    }
};
