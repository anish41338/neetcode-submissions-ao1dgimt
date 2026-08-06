class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int sum=0;
            if(i==n-1)sum=digits[i]+1;
            else sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
        }
        if(carry)digits.insert(digits.begin(),carry);
        return digits;
    }
};
