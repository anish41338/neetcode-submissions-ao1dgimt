class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())return "";
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(auto it:t)mpp1[it]++;
        int l=0;
        int minLen=INT_MAX;
        pair<int,int>p={-1,-1};
        int need=mpp1.size();
        int have=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            mpp2[c]++;
            if(mpp1[c] && mpp2[c]==mpp1[c])have++;
            while(have==need){
                if(r-l+1<minLen){
                    p={l,r};
                    minLen=r-l+1;}
                mpp2[s[l]]--;
          
                if(mpp1[s[l]] && mpp2[s[l]]<mpp1[s[l]])have--;
                l++;
            }

        }
        if(p.first==-1)return "";
        return s.substr(p.first,p.second-p.first+1);
    }
};
