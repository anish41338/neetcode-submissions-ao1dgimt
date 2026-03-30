class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l=0;
        int maxi=0;
        int best=0;
        for(int r=0;r<s.length();r++){
            int idx=s[r]-'A';
            freq[idx]++;
            maxi=max(maxi,freq[idx]);
            while(r-l+1-maxi>k){
                freq[s[l]-'A']--;
                l++;
            }
            best=max(best,r-l+1);
        }
        return best;
        
    }
};
