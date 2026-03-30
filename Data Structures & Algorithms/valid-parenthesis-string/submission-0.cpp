class Solution {
public:
    bool checkValidString(string s) {
        int leftmin=0,leftmax=0;
        for(auto x:s){
            if(x=='('){
                leftmin++;leftmax++;
            }
            else if(x==')'){
                leftmin--;leftmax--;
            }
            else{
                leftmin--;leftmax++;
            }
            if(leftmin<0)leftmin=0;
            if(leftmax<0)return false;
        }
        return leftmin==0;
        
    }
};
