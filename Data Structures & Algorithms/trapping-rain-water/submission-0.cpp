class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>maxl(height.size(),0);
        vector<int>maxr(height.size(),0);
        int n=height.size();
        int l=1;
        int r=n-2;
        while(l<n){
            int lmax=max(maxl[l-1],height[l-1]);
            maxl[l]=lmax;
            int rmax=max(maxr[r+1],height[r+1]);
            maxr[r]=rmax;
            l++;
            r--;
        }
        int water=0;
        l=0;
        while(l<n){
            int sum=min(maxl[l],maxr[l])-height[l];
            if(sum>0)water+=sum;
            l++;
        }
        return water;
        
    }
};
