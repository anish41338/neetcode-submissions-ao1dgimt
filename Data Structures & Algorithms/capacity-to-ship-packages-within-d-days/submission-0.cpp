class Solution {
public:
    bool can(int cap,vector<int>&weights,int days){\
        int day=1;
        int sum=0;
        for(auto it:weights){
            if(cap-sum<it){
                day++;
                sum=it;
            }
            else{
                sum+=it;
            }
            if(day>days)return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=0;
        for(auto it:weights)maxi+=it;
        int mini=*max_element(weights.begin(),weights.end());
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            if(can(mid,weights,days))maxi=mid-1;
            else mini=mid+1;
        }
        return mini;
    }
};