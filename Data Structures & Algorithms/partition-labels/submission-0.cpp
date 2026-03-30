class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++)mpp[s[i]]=i;
        vector<int>ans;
        int size=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            end=max(end,mpp[s[i]]);
            size++;
            if(i==end){
                ans.push_back(size);
                size=0;
            }
        }
        return ans;
    }
};