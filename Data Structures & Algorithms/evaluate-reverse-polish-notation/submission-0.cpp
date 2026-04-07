class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto x: tokens){
            if(x!="+" && x!="-" && x!="*" && x!="/")st.push(stoi(x));
            else {
                int temp1=st.top();st.pop();
                int temp2=st.top();st.pop();
                int ans=0;
                if(x=="+")ans=temp1+temp2;
                if(x=="-")ans=temp2-temp1;
                if(x=="*")ans=temp1*temp2;
                if(x=="/")ans=temp2/temp1;
                st.push((int)ans);
            }
        }
        int res=st.top();
        return res;

        
    }
};
