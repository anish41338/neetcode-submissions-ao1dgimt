/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=1;
        int r=n-2;
        int peak=0;
        while(l<=r){
            int mid=(l+r)/2;
            int left=mountainArr.get(mid-1);
            int midd=mountainArr.get(mid);
            int right=mountainArr.get(mid+1);
            if(left<midd && midd<right)l=mid+1;
            else if (left>midd && midd>right)r=mid-1;
            else {
                peak=mid;
                break;
            }
        }
        l=0;
        r=peak;
        while(l<=r){
            int mid=(l+r)/2;
            if(mountainArr.get(mid)==target)return mid;
            else if(mountainArr.get(mid)<target)l=mid+1;
            else r=mid-1;
        }
        l=peak;
        r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            int val=mountainArr.get(mid);
            if(val<target)r=mid-1;
            else if(val==target)return mid;
            else l=mid+1;

        }
        return -1;
        
    }
};