class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int i=1;
        while(st.count(i)){
            i++;
        }
        return i;
    }
};