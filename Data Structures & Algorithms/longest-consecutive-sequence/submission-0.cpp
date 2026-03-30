class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end()); 
        int best=0;
        for(auto x :s){
            if(s.find(x-1)==s.end()){
                int len=1,cur=x+1;
                while(s.find(cur)!=s.end()){
                    cur++;len++;
                }
                best=max(best,len);
            }
        }
    return best;
        
    }
};
