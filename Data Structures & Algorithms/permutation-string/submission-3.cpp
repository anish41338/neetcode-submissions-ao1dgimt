class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>m1(26,0);
        vector<int>m2(26,0);
        for(auto it:s1)m1[it-'a']++;
        int l=0;
        for(int r=0;r<s2.size();r++){
            m2[s2[r]-'a']++;
            if(m1==m2)return true;
            while(l<=r && r-l+1>s1.size()){
                m2[s2[l]-'a']--;
                l++;
                if(m1==m2)return true;
            }

        }
        return false;
    }
};
