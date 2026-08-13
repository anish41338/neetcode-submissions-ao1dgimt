class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
       // string ans="";
        for(auto it:s){

            if(it!=']')st.push(string(1,it));
            else{
                string sub="";
                while(st.top()!="["){
                    sub=st.top()+sub;
                    st.pop();
                }
                st.pop();
               // reverse(sub.begin(),sub.end());
                string k="";
                while(!st.empty() && isdigit(st.top()[0])){
                    k=st.top()+k;
                    st.pop();
                }
               // reverse(k.begin(),k.end());
                int num=stoi(k);
                string temp="";
                while(num--){
                   temp+=sub;
                }
                st.push(temp);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
       // reverse(ans.begin(),ans.end());
        return ans;
    }
};