class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int i=0;i<nums.size();i++){
            if(!st.count(nums[i]-1)){
                int cur=nums[i];
                int len=1;
                while(st.count(cur+1)){
                    cur++;
                    len++;}
                    longest=max(longest,len);
            }
        }
        return longest;
    }
};
