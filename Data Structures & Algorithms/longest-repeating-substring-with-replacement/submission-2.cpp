class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        map<char,int>mpp;
        int maxi=INT_MIN;
        int n=s.size();
        int max_ele=0;
        while(r<n){
            mpp[s[r]]++;
            max_ele=max(max_ele,mpp[s[r]]);
            int diff=(r-l+1)-max_ele;
            while( diff>k){
                mpp[s[l]]--;
                l++;
                diff=r-l+1-max_ele;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
