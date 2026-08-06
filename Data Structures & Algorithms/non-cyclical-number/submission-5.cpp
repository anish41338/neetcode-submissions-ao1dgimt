class Solution {
public:
    int sos(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            n/=10;
            sum+=digit*digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do{
            slow=sos(slow);
            fast=sos(sos(fast));

        }while(slow!=fast);
        return slow==1;
    }
};
