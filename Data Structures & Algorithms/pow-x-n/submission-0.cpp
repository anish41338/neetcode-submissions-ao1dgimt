class Solution {
public:
    double myPow(double x, int n) {
        long long m=n;
        if(m<0){
            x=1/x;
            m=-m;
        }
        double ans=1;
        while(m>0){
            if(m%2!=0){
                ans*=x;
                m-=1;
            }
            x*=x;
            m/=2;
        }
        return ans;
        
    }
};
