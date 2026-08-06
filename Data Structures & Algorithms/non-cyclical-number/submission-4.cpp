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
        int cnt=0;
        while(cnt<100){
            n=sos(n);
            if(n==1)break;
            cnt++;
        }
        return n==1;
    }
};
