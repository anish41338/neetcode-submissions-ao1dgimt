class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first=strs[0];
        for(int i=0;i<first.size();i++){
            for(int j=1;j<strs.size();j++){
                if(i>strs[j].size()||first[i]!=strs[j][i])
                    return first.substr(0,i);
            }
        }
        return first;
    }
};