class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        while(low<=high){
            int k=(high+low)/2;
            long long hrs=0;
            for(auto it:piles){
                hrs+=(it+k-1)/k;
                if(hrs>h)break;
            }
            if(hrs<=h)high=k-1;
            else low=k+1;
        }
        return low;
    }
};
