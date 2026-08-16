class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>st;
        int n=heights.size();
        for(int i=0;i<=heights.size();i++){
            int height=(i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>height){
                int idx=st.top();
                st.pop();
                int h=heights[idx];
                int width=0;
                if(st.empty())width=i;
                else width=i-st.top()-1;
                ans=max(ans,width*h);
            }
            st.push(i);
        }
        return ans;
    }
};
