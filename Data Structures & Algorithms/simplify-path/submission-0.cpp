class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        path+="/";
        string cur="";
        for(auto it:path){
            if(it=='/'){
                if(cur==".."){
                if(!st.empty())st.pop_back();}
                else if(cur!="" && cur!="."){st.push_back(cur);}
                cur="";
            }
            else{
                cur+=it;
            }
        }
        string ans="";
        for(auto it:st){
           ans+="/"+it;
        }
      
        return ans.empty()?"/":ans;
        
    }
};