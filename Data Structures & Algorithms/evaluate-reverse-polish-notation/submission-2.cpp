class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        set<string>st1;
        st1={"+","*","-","/"};
        for(int i=0;i<tokens.size();i++){
            if(!st1.count(tokens[i]))st.push(stoi(tokens[i]));
            else{
                int t1=st.top();st.pop();
                int t2=st.top();st.pop();
                string tkn=tokens[i];
                if(tkn=="+")st.push(t1+t2);
                else if(tkn=="-")st.push(t2-t1);
                else if(tkn=="*")st.push(t1*t2);
                else{
                    st.push(t2/t1);
                }
                
            }
        }
        return st.top();
    }
};
