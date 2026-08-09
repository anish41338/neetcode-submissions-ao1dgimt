class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)five++;
            else if(bills[i]==10){
                if(!five)return false;
                else{
                five--;
                ten++;}
            }
            else{
                if(!(five>=3 || (five>=1 && ten>0)))return false;
                else if(ten>0 && five>=1){
                    twenty++;
                    ten--;
                    five--;
                }
                else{
                    five-=3;
                }

            }
        }
        return true;
    }
};