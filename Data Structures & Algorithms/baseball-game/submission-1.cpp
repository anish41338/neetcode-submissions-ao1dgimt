class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto it:operations){
             if(it=="+"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2);
                st.push(t1);
                st.push(t1+t2);
            }
            else if(it=="C")st.pop();
            else if (it=="D"){
                int t3=st.top();
              
                st.push(2*t3);
            }
            else st.push(stoi(it));
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();}
            return sum;
    }
};