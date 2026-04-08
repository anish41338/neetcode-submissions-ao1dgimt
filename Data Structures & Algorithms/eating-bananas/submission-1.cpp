class Solution {
public:
    bool valid(int given,int h,vector<int>&piles ){
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i]+given-1)/given;
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(),piles.end());
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int mini=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(!valid(mid,h,piles))low=mid+1;
            else{
               mini=mid;
                high=mid-1;
            }


        }
        return mini;
        
    }
};
