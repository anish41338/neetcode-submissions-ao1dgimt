class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int n=height.size()-1;
        int r=n;
        int l=0;
        int lmax=height[l];
        int rmax=height[r];
        while(l<r){
            if(lmax<rmax){
                l++;
                lmax=max(lmax,height[l]);
                water+=lmax-height[l];
            }
            else{
                r--;
                rmax=max(rmax,height[r]);
                water+=rmax-height[r];
            }



        }
        return water;
        
    }
};
