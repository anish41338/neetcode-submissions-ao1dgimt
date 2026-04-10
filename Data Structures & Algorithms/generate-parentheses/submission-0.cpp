class Solution {
public:
    void generate(int open,int close,string cur,vector<string>&ans,int n){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return;
        }
        if(open<n){
            generate(open+1,close,cur+"(",ans,n);
        }
        if(close<open){
            generate(open,close+1,cur+")",ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string cur="";
        generate(0,0,cur,ans,n);
        return ans;
        
    }
};
