class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> mpp1(26, 0), mpp2(26, 0);
        int l = 0;
        int r = s1.length();

        for (int i = 0; i < s1.size(); i++) {
            mpp1[s1[i] - 'a']++;
            mpp2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (mpp1[i] == mpp2[i]) matches++;
        }

        while (r < s2.size()) {
            if (matches == 26) return true;

            int add = s2[r] - 'a';
            mpp2[add]++;
            if (mpp2[add] == mpp1[add]) matches++;
            else if (mpp2[add] - 1 == mpp1[add]) matches--;

            int rem = s2[l] - 'a';
            mpp2[rem]--;
            if (mpp2[rem] == mpp1[rem]) matches++;
            else if (mpp2[rem] + 1 == mpp1[rem]) matches--;

            l++;
            r++;
        }

        return matches == 26;
    }
};
