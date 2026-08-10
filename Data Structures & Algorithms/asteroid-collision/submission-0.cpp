class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(auto it:asteroids){
            bool alive=true;
            while(alive && !st.empty()&&st.back()>0 && it<0){
                if(st.back()==-it){st.pop_back();alive=false;}
                else if(st.back()>-it)alive=false;
                else{
                    st.pop_back();
                }
            }
            if(alive)st.push_back(it);
        }
        return st;
    }
};