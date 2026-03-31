class Solution {
public:
    int sumsquare(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            n/=10;
            sum+=digit*digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        n=sumsquare(n);
        while(n>=10){
            n=sumsquare(n);
        }
        return n==1;
        
        
    }
};
