class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char,int> mpp1, mpp2;
        int l = 0;
        int r = s1.length();

        for (int i = 0; i < s1.size(); i++) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        int matches = 0;
        for (auto it : mpp1) {
            if (mpp2[it.first] == it.second) matches++;
        }

        while (r < s2.size()) {
            if (matches == mpp1.size()) return true;

            char add = s2[r];
            mpp2[add]++;
            if (mpp1.count(add)) {
                if (mpp2[add] == mpp1[add]) matches++;
                else if (mpp2[add] - 1 == mpp1[add]) matches--;
            }

            char rem = s2[l];
            mpp2[rem]--;
            if (mpp1.count(rem)) {
                if (mpp2[rem] == mpp1[rem]) matches++;
                else if (mpp2[rem] + 1 == mpp1[rem]) matches--;
            }

            l++;
            r++;
        }

        return matches == mpp1.size();
    }
};
